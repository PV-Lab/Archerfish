# \#Archerfish

![Archerfish](./renderings/Archerfish_Render.png)

**Project Name:** \#Archerfish

**Project Lead:** Aleks Siemenn \<<asiemenn@mit.edu>\>

**Collaborators:** Jim Serdy, Basita Das, Eunice Aissi, Tonio Buonassisi

**Abstract**: The principle of "build fast, fail faster" has significantly shortened the timeline from ideation to final product in mechanical engineering, paralleling the rise of 3D printing technology and rapid prototyping. In contrast, material science has yet to achieve similar advancements in rapid learning cycles, hindered by the predominantly manual nature of its experimental procedures. For example, to test a material, it is conventionally synthesized at the same fidelity as industry standards, such as using manual spin coating, rather than being treated as a "rapid prototype." Implementing rapid prototyping principles into parts of these experimental procedures can help to shorten the timeline of the materials development pipeline, just as it does for mechanical design. Here, we introduce the design of Archerfish, a low-cost and high-throughput combinatorial mixing and deposition platform to accelerate the screening of material compounds. With this high-throughput combinatorial printing (HTCP) design, we demonstrate combinatorial mixing and printing throughputs of 250 unique compounds per minute. Furthermore, we validate the formation of combinatorial material gradients using hyperspectral image analysis. The proposed low-cost HTCP design expands accessibility to rapid materials screening technology, enabling scientists to make faster experimentally-informed decisions for the development of new materials. 

## Explanation of code within GitHub Repo:
### [1] Archerfish BOM.xlxs
Detailed Bill of Materials for the Archerfish System. 

### [2] /Code/Microcontroller Syringe Pump Code/Microcontroller-Syringe-Pump-Code.ino
Simple Arduino Mega gradient printing code for two 28BYJ-48 5V Stepper Motors with ULN2003 Drivers. This code drives both syringes in the archerfish system to create a gradient of droplets. Package version AccelStepper >= 1.64 and Arudino IDE >= 2.2.1 were used to develop this code.

### [3] /Code/Printer G-code/Raster Pattern.gcode
G-code for a Monoprice MP Select Mini 3D Printer to raster the gradient printed by the Archerfish system on a 100mm x 100mm polyester sheet. Marlin-flavor G-code is used to develop this code.

### [4] /Code/Script to Update G-code/Update_gcode.ipynb
Python notebook script to update an existing g-code file to the dimensions of any 3D printer bed size.

### [5] /CAD/Full Archerfish System Assembly.zip
Detailed CAD Model of the Archerfish System. Open-access CAD model of the complete Archerfish assembly can also be found on [GrabCAD](https://grabcad.com/library/archerfish-1). Included in this folder are the Solidworks files and 3D-printable STL files for all custom components.

### [6] /CAD/Droplet Generator and Junction
Contains all Solidworks part files and 3D-printable STL files to reproduce the droplet generation and junction assembly.

### [7] /CAD/Syringe Pump
Contains all Solidworks part files and 3D-printable STL files to reproduce the syringe pump holder assembly.

### [8] /data
The folder contains the paper's relevant hyperspectral, EDS, and profilometry data.

