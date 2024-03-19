# AK Motor value converter.
Translate float value [rps] -> AK motor CAN packet value.

## Requirements
 - `g++`
 - `make`


## Build
```bash
make
```

## Usage

```bash
./build/ak_pose 10.0
0x7FFF

./build/ak_vel 10.0
0x999

./build/ak_torq 0.0
0x7FF
```


