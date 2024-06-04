# \#Archerfish

![Archerfish](./renderings/Archerfish_Render.png)

**Project Name:** \#Archerfish

**Project Lead:** Aleks Siemenn \<<asiemenn@mit.edu>\>

**Collaborators:** Jim Serdy, Basita Das, Eunice Aissi, Tonio Buonassisi

**Abstract**: The principle of "build fast, fail faster" has signifi-
cantly shortened the timeline from ideation to final prod-
uct in mechanical engineering, paralleling the rise of 3D
printing technology and rapid prototyping. In contrast,
material science has yet to achieve similar advancements
in rapid learning cycles, hindered by the predominantly
manual nature of its experimental procedures. For
example, to test a material, it is conventionally synthe-
sized at the same fidelity as industry standards, such as
using manual spin coating, rather than being treated as
a "rapid prototype." Implementing rapid prototyping
principles into parts of these experimental procedures
can help to shorten the timeline of the materials devel-
opment pipeline, just as it does for mechanical design.
Here, we introduce the design of Archerfish, a low-cost
and high-throughput combinatorial mixing and depo-
sition platform to accelerate the screening of material
compounds. With this high-throughput combinatorial
printing (HTCP) design, we demonstrate combinato-
rial mixing and printing throughputs of 250 unique
compounds per minute. Furthermore, we validate the
formation of combinatorial material gradients using
hyperspectral image analysis. The proposed low-cost
HTCP design expands accessibility to rapid materials
screening technology, enabling scientists to make faster
experimentally-informed decisions for the development
of new materials. 

## Explanation of code within GitHub Repo:
### [1] Archerfish BOM.xlxs
Detailed Bill of Materials for the Archerfish System. 

### [2] 2_Motor_step_V4_AS.ino
Simple Arduino Mega gradient printing code for two 28BYJ-48 5V Stepper Motors with ULN2003 Drivers. This code drives both syringes in the archerfish system to create a gradient of droplets. 

### [3] Raster_R5_MP.gcode
G-code for a Monoprice MP Select Mini 3D Printer to raster the gradient printed by the Archerfish system on a 100mm x 100mm polyester sheet. 

### [4] Archerfish.step
Detailed CAD Model of the Archerfish System. 

### [5] Archerfish_UI_Box.png
Rendering of the User Interface Box.

### [6] Archerfish_render_complete_R2.png
Rendering of the whole Archerfish System.

### [7] Junction_nozzle_mixing_R2.png
Rendering of the Junction and Nozzle assembly. 

### [8] Syringe_pump_construction_R2.png
Rendering of the Syringe Pumps.  

