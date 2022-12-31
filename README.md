<div align="center">
    <img width="128" src="https://github.com/AshitaXI/Ashita/raw/master/repo/ashita.png" alt="ashita">
    </br>
</div>

<div align="center">
    <a href="https://ashitaxi.com/"><img src="https://img.shields.io/website?down_message=ashitaxi.com&style=for-the-badge&up_message=ashitaxi.com&url=https%3A%2F%2Fashitaxi.com%2F" alt="Website" /></a>
    <a href="https://discord.gg/Ashita"><img src="https://img.shields.io/discord/264673946257850368.svg?style=for-the-badge" alt="Discord server" /></a>
    <a href="LICENSE"><img src="https://img.shields.io/badge/License-LGPL_v3-blue?style=for-the-badge" alt="license" /></a>
    <br/>
</div>

<br/>

# Ashita v4 Example Plugin

This repository contains the source code to the current template used to create plugins for Ashita v4.

# Requirements

In order to compile this project, you need the following:

  - `Microsoft Visual Studio 2022` - https://visualstudio.microsoft.com/vs/

## SDK Environment Variable Setup

This project makes use of an environment variable (`ASHITA4_SDK_PATH`) to locate and use the Ashita v4 SDK.\
You will need to set this path on your system in order to make use of this project properly.

To add a new environment variable, you can follow these quick steps:

  1. Click `Start`.
  2. Type in `advanced system settings` and choose the option that shows. _(`View advanced system settings`)_
  3. If not already selected, click the `Advanced` tab at the top.
  4. Click the `Environment Variables` button near the bottom of the window.
  5. Under `User variables..` click the `New` button.
  6. For `Variable name`, enter: `ASHITA4_SDK_PATH`
  7. For `Variable value`, enter the path to your Ashita SDK folder. _(This is located in the `/plugins/` folder where you have Ashita installed.)_
      - For example, `C:\Ashita\plugins\sdk\`
  8. Click `Ok` on all windows to save the changes.

At this point, restart any instance of `Visual Studio` you have open, along with any command line prompts or terminals.\
`Visual Studio` should now see the SDK path automatically and allow the example plugin source code to compile.

# License

The Ashita plugin SDK, and thus, this plugins source code are both released under [GNU LGPL v3](https://github.com/AshitaXI/ExamplePlugin/blob/main/LICENSE.md)
