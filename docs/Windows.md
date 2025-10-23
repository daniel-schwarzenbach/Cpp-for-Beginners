# Windows

## Install Chocolatey (Package Manager for Windows)

![Choocolatey Logo](./pics/chocolatey.png)

- Open PowerShell as Administrator.
  - Press Windows Key.
  - Type powershell.
  - Right-click on Windows PowerShell in the search results.
  - Select Run as administrator.
- Run the following command to install Chocolatey:

```powershell
Set-ExecutionPolicy Bypass -Scope Process -Force;
[System.Net.ServicePointManager]::SecurityProtocol = [System.Net.SecurityProtocolType]::Tls12;
iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```

altnatively, you can install Chocolatey by downloading the installer from  <https://chocolatey.org/install>.

Close and reopen PowerShell and ensure Chocolatey is available.

```powershell
choco --version
```

##  Install the Required Packages

Once Chocolatey is installed, you can install the required packages for C++ development:

open a new PowerShell/Cmd Prompt window and run the following commands:


```powershell
# install the compiler
choco install mingw

# install Git
choco install git

# install CMake
choco install make
choco install cmake
```

Install VSCode from the official website: [VSCode](https://code.visualstudio.com/)

Install Julia from the official website: [Julia](https://julialang.org/install/)

### Verify the Installations

```powershell
git --version
g++ --version
gdb --version
```

[Go Back to Guide](../Readme.md#installation-guide)
