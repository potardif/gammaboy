package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

type instr struct {
	operation string
	operands  []string
}

func main() {
	var jumpTable [256]*instr
	buildJumpTable(&jumpTable)
	printJumpTable(&jumpTable, "opcodes.cpp")

	var extendedJumpTable [256]*instr
	buildExtendedJumpTable(&extendedJumpTable)
	printJumpTable(&extendedJumpTable, "extended_opcodes.cpp")
}

func printJumpTable(jumpTable *[256]*instr, dst string) {
	f, err := os.Create(dst)
	check(err)
	defer f.Close()

	for opcode, instr := range jumpTable {
		if instr == nil {
			continue
		}

		strArgs1 := ""
		if len(instr.operands) > 0 {
			strArgs1 = " " + strings.Join(instr.operands, ", ")
		}

		strArgs2 := strings.Join(
			append([]string{"gb"}, instr.operands...),
			", ",
		)

		fmt.Fprintf(f, "case 0x%02X:\n", opcode)
		fmt.Fprintf(f, "\tif (gb->log) {\n")
		fmt.Fprintf(f, "\t\tprintf(\"%s%s\\n\");\n", instr.operation, strArgs1)
		fmt.Fprintf(f, "\t}\n")
		fmt.Fprintf(f, "\t%s(%s);\n", instr.operation, strArgs2)
		fmt.Fprintf(f, "\tbreak;\n")
	}
}

var R1 = map[string]string{
	"0": "BC",
	"1": "DE",
}

var R2 = map[string]string{
	"00": "BC",
	"01": "DE",
	"10": "HL",
	"11": "SP",
}

var R3 = map[string]string{
	"00": "BC",
	"01": "DE",
	"10": "HL",
	"11": "AF",
}

var D_operands = map[string]string{
	"000": "B",
	"001": "C",
	"010": "D",
	"011": "E",
	"100": "H",
	"101": "L",
	"110": "mem(HL)",
	"111": "A",
}

var F_operands = map[string]string{
	"00": "F.NZ",
	"01": "F.Z",
	"10": "F.NC",
	"11": "F.C",
}

var ALU = map[string]string{
	"000": "ADD",
	"010": "SUB",
	"101": "XOR",
	"111": "CP",
}

var N = map[string]string{
	"000": "0",
	"001": "1",
	"010": "2",
	"011": "3",
	"100": "4",
	"101": "5",
	"110": "6",
	"111": "7",
}

func buildJumpTable(jumpTable *[256]*instr) {
	add := getAddFunctionFromJumpTable(jumpTable)

	// NOP
	// LD (N),SP

	// LD R,N
	for ii, x := range R2 {
		add("00"+ii+"0001", "LD", x, "imm_u16")
	}

	// ADD HL,R

	// LD (R),A
	for i, x := range R1 {
		add("000"+i+"0010", "LD", "mem("+x+")", "A")
	}

	// LD A,(R)
	for i, x := range R1 {
		add("000"+i+"1010", "LD", "A", "mem("+x+")")
	}

	// INC R
	for ii, x := range R2 {
		add("00"+ii+"0011", "INC_u16", x)
	}

	// DEC R

	// INC D
	for iii, x := range D_operands {
		add("00"+iii+"100", "INC_u8", x)
	}

	// DEC D
	for iii, x := range D_operands {
		add("00"+iii+"101", "DEC", x)
	}

	// LD D,N
	for iii, x := range D_operands {
		add("00"+iii+"110", "LD", x, "imm_u8")
	}

	// RdCA

	// RdA
	add("00010111", "RLA")
	// TODO RRA

	// STOP

	// JR N
	add("00011000", "JR", "imm_i8")

	// JR F,N
	for ii, x := range F_operands {
		add("001"+ii+"000", "JR", x, "imm_i8")
	}

	// LDI (HL),A
	add("00100010", "LDI", "mem(HL)", "A")

	// LDI A,(HL)
	add("00101010", "LDI", "A", "mem(HL)")

	// LDD (HL),A
	add("00110010", "LDD", "mem(HL)", "A")

	// LDD A,(HL)
	add("00111010", "LDD", "A", "mem(HL)")

	// DAA
	// CPL
	// SCF
	// CCF

	// LD D,D
	for iii, x := range D_operands {
		for jjj, y := range D_operands {
			if !(iii == "110" && jjj == "110") {
				add("01"+iii+jjj, "LD", x, y)
			}
		}
	}

	// HALT

	// ALU A,D
	for iii, operation := range ALU {
		for jjj, x := range D_operands {
			add("10"+iii+jjj, operation, x)
		}
	}

	// ALU A,N
	for iii, operation := range ALU {
		add("11"+iii+"110", operation, "imm_u8")
	}

	// POP R
	for ii, x := range R3 {
		add("11"+ii+"0001", "POP", x)
	}

	// PUSH R
	for ii, x := range R3 {
		add("11"+ii+"0101", "PUSH", x)
	}

	// RST N
	// RET F

	// RET
	add("11001001", "RET")

	// RETI
	// JP F,N
	// JP N
	// CALL F,N

	// CALL N
	add("11001101", "CALL", "imm_u16")

	// ADD SP,N
	// LD HL,SP+N

	// LD (0xFF00+N),A
	add("11100000", "LD", "mem(FF00(imm_u8))", "A")

	// LD A,(0xFF00+N)
	add("11110000", "LD", "A", "mem(FF00(imm_u8))")

	// LD (0xFF00+C),A
	add("11100010", "LD", "mem(FF00(C))", "A")

	// LD A,(0xFF00+C)
	add("11110010", "LD", "A", "mem(FF00(C))")

	// LD (N),A
	add("11101010", "LD", "mem(imm_u16)", "A")

	// LD A,(N)
	add("11111010", "LD", "A", "mem(imm_u16)")

	// JP HL
	// LD SP,HL
	// DI
	// EI
}

func buildExtendedJumpTable(jumpTable *[256]*instr) {
	add := getAddFunctionFromJumpTable(jumpTable)

	// RdC

	// Rd D
	for iii, x := range D_operands {
		add("00010"+iii, "RL", x)
	}
	// TODO RR

	// SdA D
	// SWAP D
	// SRL D

	// BIT N,D
	for iii, x := range N {
		for jjj, y := range D_operands {
			add("01"+iii+jjj, "BIT", x, y)
		}
	}

	// RES N,D
	// SET N,D
}

func addOpcode(jumpTable *[256]*instr, strOpcode, operation string,
	operands []string) {
	assert(len(strOpcode) == 8)

	const base = 2
	const bitsize = 8
	opcode, err := strconv.ParseUint(strOpcode, base, bitsize)
	check(err)

	assert(0x00 <= opcode && opcode <= 0xFF)
	assert(jumpTable[opcode] == nil)
	jumpTable[opcode] = &instr{operation, operands}
}

func getAddFunctionFromJumpTable(jumpTable *[256]*instr,
) func(strOpcode, operation string, operands ...string) {
	return func(strOpcode, operation string, operands ...string) {
		addOpcode(jumpTable, strOpcode, operation, operands)
	}
}

func assert(cond bool) {
	if !cond {
		panic("Assertion failed.")
	}
}

func check(err error) {
	if err != nil {
		panic(err)
	}
}
