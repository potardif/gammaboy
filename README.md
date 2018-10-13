# gammaboy

gammaboy is a work-in-progress Game Boy emulator written in C++.

## Compilation

### On Ubuntu

```terminal
sudo apt install clang
sudo apt install nettle-dev
sudo apt install make
make
```

### On Fedora

```terminal
sudo dnf install clang
sudo dnf install nettle-devel
sudo dnf install make
make
```

## Usage

```terminal
./gammaboy path/to/DMG_bios
```

The DMG bios is a 256-byte file with this SHA-256 hash:

```
cf053eccb4ccafff9e67339d4e78e98dce7d1ed59be819d2a1ba2232c6fce1c7
```

## License

```
Copyright (C) 2018  Pierre Olivier Tardif <pierre.o.tardif+license@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
```
