# ESP8266 Gemini AI Speech Interface with LCD

This project uses an ESP8266 microcontroller to communicate with an online Gemini AI service for speech synthesis and recognition. The results are displayed on an LCD screen.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Setup and Installation](#setup-and-installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This project connects an ESP8266 microcontroller to an online Gemini AI service to enable speech synthesis and recognition capabilities. The ESP8266 sends and receives data to/from the Gemini AI service, and the results are displayed on an LCD screen.

## Features

- Speech recognition using Gemini AI
- Speech synthesis using Gemini AI
- Results displayed on an LCD screen
- Wi-Fi connectivity with ESP8266

## Hardware Requirements

- ESP8266 microcontroller (e.g., NodeMCU, Wemos D1 Mini)
- LCD screen (e.g., 16x2 LCD with I2C module)
- Power supply (e.g., USB power or battery pack)
- Connecting wires

## Software Requirements

- Arduino IDE
- ESP8266 board library
- LiquidCrystal_I2C library (for the LCD)
- Gemini AI API credentials

## Setup and Installation

1. **Install Arduino IDE**: Download and install the Arduino IDE from the [official website](https://www.arduino.cc/en/software).

2. **Install ESP8266 Board Library**:
    - Open the Arduino IDE.
    - Go to `File` > `Preferences`.
    - In the "Additional Board Manager URLs" field, add the following URL: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`.
    - Go to `Tools` > `Board` > `Boards Manager`.
    - Search for `esp8266` and install the latest version.

3. **Install Required Libraries**:
    - Open the Arduino IDE.
    - Go to `Sketch` > `Include Library` > `Manage Libraries`.
    - Search for and install the following libraries:
        - `WiFiClient`
        - `HTTPClient`
        - `LiquidCrystal_I2C`

4. **Get Gemini AI API Credentials**:
    - Sign up for the Gemini AI service and obtain your API key and endpoint URL.

5. **Clone the Repository**:
    - Clone this repository to your local machine using `git clone https://github.com/yourusername/esp8266-gemini-ai-speech-lcd.git`.

6. **Configure the Code**:
    - Open the cloned repository in the Arduino IDE.
    - Update the `config.h` file with your Wi-Fi credentials and Gemini AI API credentials.
    - Update the `lcd_config.h` file with your LCD's I2C address and dimensions.

7. **Upload the Code**:
    - Connect your ESP8266 to your computer.
    - Select the appropriate board and port in the Arduino IDE.
    - Click on the upload button to upload the code to your ESP8266.

## Usage

1. **Power on the ESP8266**: Once powered, the ESP8266 will connect to the configured Wi-Fi network and communicate with the Gemini AI service.

2. **Speech Recognition and Synthesis**: The ESP8266 will send requests to the Gemini AI service and display the responses on the LCD screen.

## Contributing

Contributions are welcome! Please fork this repository and submit pull requests with your improvements and bug fixes.

1. Fork the repository.
2. Create a new branch: `git checkout -b my-feature-branch`.
3. Make your changes and commit them: `git commit -am 'Add new feature'`.
4. Push to the branch: `git push origin my-feature-branch`.
5. Submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
