# SSDT Index
Ready-to-use headers for SSDT indecies

### Supported OS Version:
* Windows 10 20H1 (ver 2004, build 19041)


## Example
```
// Compile-Time
int _index = SSDT_Index::Win10_20H1::NtCreateThread;

// Runtime
int build_ver = 19041;
// check if build ver supported
bool ssdt_supported = IsBuildVerSupported(build_ver);
// get index for build ver
int _index = GetSSDTIndex(NtCreateThread, build_ver);   // return -1 if build_ver not supported

// if you ever needed the SSDTMap class
auto ssdt_map = GetSSDTMap(NtCreateThread);

```


## How to Contribute
* Send a PR with reversing brief.
* Setup a kernel debugee and make it accessable from the internet, then open an issue.
* Come up with a better idea of managing headers.