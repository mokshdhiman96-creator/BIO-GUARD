::: {align="center"}
# BIO-GUARD 🌱

### Smart Soil, Temperature & Ambient Light Monitoring System

**A practical environmental monitoring project for agricultural
observation.**

[![Platform](https://img.shields.io/badge/Controller-Arduino%20Uno%20R3-00979D?style=for-the-badge&logo=arduino&logoColor=white)](#)
[![Sensors](https://img.shields.io/badge/Sensors-Soil%20%7C%20DHT11%20%7C%20LDR-2E8B57?style=for-the-badge)](#)
[![Project](https://img.shields.io/badge/Type-Agricultural%20Monitoring-355C7D?style=for-the-badge)](#)
:::About BIO-GUARD
BIO-GUARD is a mid-sized agricultural monitoring project designed to
help farmers and users observe three environmental parameters:
- Soil moisture --- using a capacitive soil-moisture sensor.
- Temperature and humidity --- using a DHT11 sensor.
- Ambient light intensity --- using a three-pin LDR module.
The system uses an Arduino Uno R3 to read sensor data. These
readings can help users observe changing conditions around a plant and
provide a foundation for future irrigation-support and plant-monitoring
features.

BIO-GUARD is a monitoring prototype. It does not independently guarantee
plant health or automatically irrigate crops in its current documented
configuration.
Key Features
- Soil-moisture monitoring --- reads the capacitive sensor's
  output to observe changes in soil moisture.
- Temperature monitoring --- reads surrounding temperature using
  the DHT11.
- Humidity monitoring --- reads relative humidity using the DHT11.
- Ambient-light monitoring --- reads the LDR module's response to
  surrounding light.
- Multi-sensor integration --- combines three sensor inputs with
  an Arduino Uno R3.
- Expandable design --- provides a starting point for future data
  logging, alerts and irrigation-support features.
Note: The LDR module's raw output is not automatically a calibrated
measurement in lux. A calibrated light sensor and suitable measurement
method are needed for accurate luminous-intensity values.

Hardware Components
  Component                              Quantity Purpose
  Arduino Uno R3                                1 Main microcontroller
Small breadboard                              1 Circuit prototyping
Three-pin LDR module                          1 Ambient-light sensing
Capacitive soil-moisture sensor               1 Soil-moisture sensing
DHT11 sensor                                  1 Temperature and humidity sensing
Jumper cables                       As required Electrical connections
System Overview
1. The capacitive soil-moisture sensor measures a soil-related
   electrical response.
2. The DHT11 provides temperature and relative-humidity readings.
3. The LDR module responds to the surrounding light level.
4. The Arduino Uno R3 reads and processes the sensor signals.
5. The readings can be used to observe environmental changes around the
   plant.
Example Arduino Pin Plan
The following is a suggested pin plan for the listed modules. Confirm
the labels and pinout on your exact sensor boards before wiring.

  Sensor / module pin                    Arduino Uno R3
  DHT11 data                             D2
Capacitive soil sensor analog output   A0
LDR module analog output (AO)          A1
Sensor VCC                             Suitable supply as specified by the module
Sensor GND                             GND

If your LDR module exposes both AO and DO, use AO when you want a
changing analog reading. DO is a threshold-based digital output.
Calibration & Measurement Notes
Sensor readings depend on the specific module, wiring, supply voltage,
placement and surrounding conditions.
- Soil moisture: Record readings in representative dry and moist
  soil conditions. Use those reference readings to interpret the
  sensor's range.
- Temperature and humidity: Use the DHT11 within its specified
  operating conditions; allow readings to stabilize.
- Ambient light: Treat the LDR reading as a relative sensor value
  unless the system has been calibrated against a suitable
  light-measurement instrument.
Do not assume that a particular raw analog value always means "dry,"
"wet," "bright" or "dark" across every module. Verify the direction and
range with your own hardware.
Safety Notes
- Verify the voltage requirements and pin labels of every module
  before powering the circuit.
- Keep the Arduino, breadboard and electrical connections protected
  from water and damp soil.
- Do not place the electronic circuit where irrigation water can reach
  it.
- Disconnect power before changing wiring.
- If adding a pump in a future version, use a properly rated driver or
  relay and a suitable separate power supply. Never power a pump
  directly from an Arduino GPIO pin.
Future Improvements
Potential future extensions include:
- A display for live sensor readings.
- Data logging to track environmental changes over time.
- Configurable soil-moisture thresholds.
- Alerts when readings cross configured thresholds.
- A properly interfaced water-pump control system.
- Field testing across different soil types and plant conditions.
These are possible improvements and should not be considered implemented
until they have been built and tested.
Project Status
Hardware monitoring prototype. Document the completed wiring, source
code, calibration readings and test results as the project develops.
Author
Moksh Dhiman
Robotics • AI • Electronics • Scientific Innovation
::: {align="center"}
**BIO-GUARD --- Observe the environment. Make informed growing
decisions.** 🌱
:::
