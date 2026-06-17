# Project Structure

This document provides a detailed overview of the directory hierarchy and contents of the **Smoke-Detector-System** repository.

---

```
Smoke-Detector-System/
├── LICENSE                    # MIT License for the project
├── README.md                  # Main portfolio presentation and project overview
├── CONTRIBUTING.md            # Guidelines on how to contribute
├── INSTALLATION.md            # Detailed hardware connections and software steps
├── PROJECT_STRUCTURE.md       # Directory layout and explanation (this file)
├── RESULTS.md                 # Detailed experimentation data and graphs
│
├── ASSETS/                    # Visual assets and diagrams used in documentation
│   ├── Project_Banner.png     # Repository banner image
│   ├── GitHub_Cover.png       # Social media/repository preview cover
│   ├── Architecture_Diagram.png # IoT layered architecture representation
│   └── Flowchart.png          # Program logic flowchart
│
├── CIRCUIT_DIAGRAM/           # Diagrams representing circuit connections
│   ├── Circuit_Diagram.png    # Breadboard and electrical schematic diagrams
│   └── Block_Diagram.png      # High-level system block diagram
│
├── CODE/                      # Main source code directory
│   └── Smoke_Detector.ino     # Complete, commented Arduino/NodeMCU source file
│
├── DOCUMENTS/                 # Academic documents and report backups
│   ├── Project_Report.pdf     # Scanned/digitized final project report
│   ├── Presentation.pptx      # PowerPoint slides for academic defense
│   └── Abstract.pdf           # One-page formal project abstract
│
├── HARDWARE_IMAGES/           # Photographic records of the prototype hardware
│   ├── Hardware_Setup.png     # Labeled visual setup guide
│   ├── Prototype_1.jpg        # Close-up image of core electronic components
│   ├── Prototype_2.jpg        # Angled snapshot of breadboard circuit
│   └── Final_Setup.jpg        # Enclosed final design prototype
│
├── OUTPUTS/                   # Concrete status outputs for README reference
│   ├── Output_1.png           # Environment Normal state status card
│   ├── Output_2.png           # Smoke Detected state status card
│   └── Output_3.png           # Fire Alert warning state status card
│
├── RESULTS/                   # Result visualizations, sensor graphs, and images
│   ├── Normal_Condition.png   # LCD display capture in safe air
│   ├── Smoke_Detected.png     # LCD display capture under light smoke
│   ├── Fire_Alert.png         # LCD display capture under heavy smoke
│   ├── LCD_Output.png         # Side-by-side LCD compile
│   └── Sensor_Graph.png       # Real-time MQ-2 calibration and response graph
│
└── SIMULATION/                # Simulation files and outputs from CAD software
    ├── Proteus_Design.pdsprj  # CAD simulation design project file (Proteus)
    ├── Proteus_Simulation.png # Circuit schematic simulation capture
    ├── Simulation_Result_1.png # Oscilloscope waveform representation
    └── Simulation_Result_2.png # Simulation Virtual Terminal log logs
```

---

## Folder Details

- **ASSETS/**: Contains graphic banners and covers that give the repository a clean, professional aesthetic on GitHub, as well as the high-level flowchart and architecture diagram.
- **CIRCUIT_DIAGRAM/**: Houses diagrams detailing components and visual layouts, critical for other developers trying to replicate the physical hardware connections.
- **CODE/**: Holds the target code running on the ESP8266 NodeMCU.
- **DOCUMENTS/**: Holds academic files, including the full Project Report (pdf), presentation slides (pptx), and a short project abstract (pdf).
- **HARDWARE_IMAGES/**: Visual evidence of prototype construction showing the physical assembly of modules.
- **OUTPUTS/**: Informational panels representing state conditions (Safe Air, Smoke, Fire).
- **RESULTS/**: Detailed screenshots showing sensor readings, I2C outputs, and generated analysis charts.
- **SIMULATION/**: Contains the Proteus project and screenshots showing computer-aided simulation results, helpful for verifying code behavior without physical hardware.
