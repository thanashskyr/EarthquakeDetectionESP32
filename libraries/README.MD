<h1 align = "center">🌟LilyGo LoRa Series🌟</h1>

## **English | [中文](./README_CN.MD)**


<h3 align = "left">Quick start:</h3>

## USE Arduino IDE

1. Install the current upstream Arduino IDE at the 1.8 level or later. The current version is at the [Arduino website](http://www.arduino.cc/en/main/software). (NOTE: MacOS may require that you install separate drivers to interact with your board. You will get error messages that occur when the IDE attempts to upload code. You should consider running the Arduino IDE in a Virtual Machine on Linux. Installing other drivers on your Mac is out of scope for this document.)
2. Start Arduino and open Preferences window. In additional board manager add url: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json` If you have multiple URLs (e.g., for other boards), just add previously mentioned URL, separated by a comma.
3. Copy all folders in the `libdeps` directory to your Arduino Libraries Directory,
- in MacOS, it is `~/Documents/Arduino/libraries`
- in Linux, it is `~/Arduino/libraries` 
- in Windows, it is `Documents/Arduino/libraries` 
4. Open the corresponding example
5. In the Arduino Application, navigate to the Board Manager menu ("Tools => Board => Board Manager"), search for `esp32`, and make sure that you install the latest version. After you do this, you can select the board you have from the list of boards in the "ESP32 Arduino" menu ("Tools=> Board => ESP32 Arduino"). It's very important to note that the list of boards is NOT in alphabetical order. Look for the board you are working with carefully in the list. `T-Beam` users can choose `TTGO T-Beam`, `lora32(T3)` users can choose `ESP32 Dev Module` , `T-Motion` users choose `Nucleo_l073RZ`
6. Select the port of the board in the port
7. For other examples except the `GPS` directory, please **uncomment** in the upper part of `utilities.h` according to your board model, otherwise the compilation will report an error
8. Upload

<h3 align = "left">Product 📷:</h3>

|           Product           |                                                         Product  Link                                                         |                                                                   Schematic                                                                    |        Corresponding example macro definition         |
| :-------------------------: | :---------------------------------------------------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------------------------------------------------------------------: | :---------------------------------------------------: |
|    [T-Beam SX1278/76 ]()    |                                [Product link](https://pt.aliexpress.com/item/32967228739.html)                                | [TBeamV0.7](schematic/LilyGo_TBeam_V0.7.pdf)/     [TBeamV1.0](schematic/LilyGo_TBeam_V1.0.pdf)/  [TBeamV1.1 ](schematic/LilyGo_TBeam_V1.1.pdf) | LILYGO_TBeam_V0_7/LILYGO_TBeam_V1_0/LILYGO_TBeam_V1_1 |
|      [T-Beam SX1262]()      |                               [Product link](https://pt.aliexpress.com/item/4001287221970.html)                               | [TBeamV0.7](schematic/LilyGo_TBeam_V0.7.pdf)/     [TBeamV1.0](schematic/LilyGo_TBeam_V1.0.pdf)/  [TBeamV1.1 ](schematic/LilyGo_TBeam_V1.1.pdf) | LILYGO_TBeam_V0_7/LILYGO_TBeam_V1_0/LILYGO_TBeam_V1_1 |
|   [LoRa32 V1.0 SX1276]()    |                                [Product link](https://pt.aliexpress.com/item/32842155838.html)                                |                                                                       ❌                                                                        |                    LILYGO_T3_V1_0                     |
|   [LoRa32 V1.0 SX1278]()    |                                [Product link](https://pt.aliexpress.com/item/32842155838.html)                                |                                                                       ❌                                                                        |                    LILYGO_T3_V1_0                     |
|   [LoRa32 V1.3 SX1276]()    |                               [Product link](https://pt.aliexpress.com/item/4000628100802.html)                               |                                                      [LoRa32 V1.3](schematic/T3_V1.3.pdf)                                                      |                    LILYGO_T3_V1_3                     |
|       [LoRa32 V2.0]()       |                                [Product link](https://pt.aliexpress.com/item/32847443952.html)                                |                                                      [LoRa32 V2.0](schematic/T3_V2.0.pdf)                                                      |                    LILYGO_T3_V1_3                     |
| [LoRa32 V2.1_1.6 Version]() | [AliExpress](https://pt.aliexpress.com/item/32872078587.html)/[Amazon](https://www.amazon.com/dp/B09SHRWVNB?ref=myi_title_dp) |                                                    [LoRa32 V2.1_1.6](schematic/T3_V1.6.pdf)                                                    |                    LILYGO_T3_V1_6                     |
|      [T-Motion S76G]()      |                              [Product link](https://www.aliexpress.com/item/4000571051141.html)                               |                                                       [T-Motion](schematic/T-Motion.pdf)                                                       |                    LILYGO_T3_V1_6                     |
|    [LoRa32 V1.8 2.4G]()     |                                🔱[Product link](https://www.lilygo.cc/products/lora-v1-8-esp32)                                |                                                   [LoRa32 V1.8 2.4G](schematic/T3_V1.8.pdf)                                                    |                    LILYGO_T3_V1_8                     |

## Example description


```
examples
├─ArduinoLoRa                                   # Just only support SX1276/SX1278 radio module
│  ├─LoRaReceiver
│  └─LoRaSender
├─GPS                                           # T-Beam GPS demo examples
│  ├─Example1_BasicNMEARead
│  ├─Example2_NMEAParsing
│  ├─Example3_FactoryDefaultsviaSerial
│  ├─TinyGPS_Example
│  └─TinyGPS_KitchenSink
├─OLED                                          # OLED demo examples
│  ├─SSD1306SimpleDemo
│  └─SSD1306UiDemo
├─RadioLibExamples                              # RadioLib examples,Support SX1276/78/62/80
│  ├─SX1262
│  │  ├─SX1262_Receive_Interrupt
│  │  └─SX1262_Transmit_Interrupt
│  ├─SX1268
│  │  ├─SX1268_Receive_Interrupt
│  │  └─SX1268_Transmit_Interrupt
│  ├─SX1276
│  │  ├─SX1276_Receive_Interrupt
│  │  └─SX1276_Transmit_Interrupt
│  ├─SX1278
│  │  ├─SX1278_Receive
│  │  ├─SX1278_Receive_Interrupt
│  │  ├─SX1278_Transmit
│  │  └─SX1278_Transmit_Interrupt
│  ├─SX1280
│  │  ├─SX128x_Receive_Interrupt
│  │  └─SX128x_Transmit_Interrupt
│  └─TBeamAllFunction                           # T-Beam all function example
├─SleepTest
└─TTN                                           # OTAA method Join TTN example
    └─TTN_OTTA

```

<h3 align = "left">Radio resolution:</h3>

How to distinguish the model of Radio just need to look at the sticker on the board, 
433MHz is SX1278,
868MHz is SX1276,
If the label says SX1262 then it is SX1262


<h3 align = "left">Precautions :</h3>

1. If there is no data output from GPS, [see Restoring factory defaults ](firmware/NMEA_Reset/README.MD)

<h3 align = "left">PinOut :</h3>

- See [utilities.h](examples/ArduinoLoRa/LoRaReceiver/utilities.h)

<h3 align = "left">Application :</h3>

- [T-Beam SoftRF](https://github.com/lyusupov/SoftRF)
- [T-Beam Paxcounter](https://github.com/cyberman54/ESP32-Paxcounter)
- [T-Beam Meshtastic](https://github.com/meshtastic/Meshtastic-device)

### TTN

To quickly start using TTN (The Things Network), please refer to [LilyGo_LoRa_Series_Quick_Start](./docs/en/LilyGo_LoRa_Series_Quick_Start_On_TTN.md)

<h3 align = "left">Datasheet :</h3>

- [AXP192](http://www.x-powers.com/en.php/Info/product_detail/article_id/29)
- [SX1262](https://www.semtech.com/products/wireless-rf/lora-transceivers/sx1262)
- [SX1278](https://www.semtech.com/products/wireless-rf/lora-transceivers/sx1278)
- [SX1276](https://www.semtech.com/products/wireless-rf/lora-transceivers/sx1276)
- [SX1280](https://www.semtech.com/products/wireless-rf/lora-24ghz/sx1280)
- [GSP NEO-6/NEO-8](https://www.u-blox.com/en/product/neo-6-series)



<h3 align = "left">Announcements :</h3>

1. After setting the LoRa output power, set the lowest current. Set sx1262 as follows :

```
    // digitalWrite(LoRa_Busy, LOW);
    // set output power to 10 dBm (accepted range is -17 - 22 dBm)
    if (radio.setOutputPower(22) == RADIOLIB_ERR_INVALID_OUTPUT_POWER) {
        Serial.println(F("Selected output power is invalid for this module!"));
        while (true);
    }


    // set over current protection limit to 80 mA (accepted range is 45 - 240 mA)
    // NOTE: set value to 0 to disable overcurrent protection
    if (radio.setCurrentLimit(80) == RADIOLIB_ERR_INVALID_CURRENT_LIMIT) {
        Serial.println(F("Selected current limit is invalid for this module!"));
        while (true);
    }
```
