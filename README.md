# Nuvoton Visual Studio Code Template
## Usage
### To clone this project
This project work with submodule from Nuvoton corporation. You need to initialize submodules by passing ``--recurse-submodules`` to the ``git clone`` command.
```
git clone https://github.com/danchouzhou/Nuvoton-VScode-template.git --recurse-submodules
```

### Build tools
Since we use VScode setting.json provide the build environment, only the execution binary need to be download (without installing). Download the following files, extract to the path which specific in ``.vscode/setting.json``.
- [gcc-arm-none-eabi-10.3-2021.07-win32.zip](https://developer.arm.com/downloads/-/gnu-rm)
- [xpack-windows-build-tools-4.3.0-1-win32-x64.zip
](https://github.com/xpack-dev-tools/windows-build-tools-xpack/releases/tag/v4.3.0-1)

### Build the template
If you want to build the target for Nuvoton M480 series for example. Open a terminal inside the VScode.
```
cd NuMicro-M4/HelloWorld
```
Simply make. HelloWorld.bin should be inside the Object folder.
```
make
```
![image](screenshot.png)

### Create your own project from this template
1. Add BSP submodule from [OpenNuvoton](https://github.com/OpenNuvoton). For example:
```
git submodule add https://github.com/OpenNuvoton/M480BSP.git NuMicro-M4/M480BSP
```
2. Edit ``CORTEX_M``, ``BASE``, ``DEVICE`` in the ``makefile.conf``.
3. Edit ``ARM_MATH_CM4`` if you are using M0.

## Reference
- [Git - Submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules)
- [Set global $PATH environment variable in VS Code - Stack Overflow](https://stackoverflow.com/questions/43983718/set-global-path-environment-variable-in-vs-code)