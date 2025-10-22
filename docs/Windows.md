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

open a new PowerShell window and run the following commands:


```powershell
# install the compiler
choco install mingw

# install the debugger
choco install mingw-gdb

# install Visual Studio Code
choco install vscode

# install Git
choco install git

# install CMake
choco install cmake
```

### Verify the Installations

```powershell
mingw32-gcc --version
mingw32-g++ --version
mingw32-gdb --version
git --version
code --version
gdb --version
```

[Go Back to Guide](../Readme.md#installation-guide)
