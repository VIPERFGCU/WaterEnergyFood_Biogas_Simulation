# WaterEnergyFood_Biogas_Simulation

## Introduction

Welcome to the Water-Energy-Food (WEF) Nexus project's Virtual Reality (VR) simulation repository. This project focuses on converting food waste into usable energy and fertilizer through the utilization of a biodigester. Led by Dr. Seneshaw Tsegaye from the Environmental Engineering Department at Florida Gulf Coast University, this endeavor is part of the larger Sustainable Cities and Societies initiative aimed at developing methods and technologies to enhance resource management in the face of increasing scarcity.

## Project Overview

The primary objective of this project is to expand and refine the VR simulation of the WEF system, which is currently operational at the Emerging Technology Institute. The simulation, initially developed as a Senior Capstone Project by Garrett Chapman, Garrett Fairburn, Jirawat Hirunkam, and Thomas Price-Gedrites, was later refreshed and expanded upon by Jordan Kooyman before being handed to Jackson Bryant to continue feature additions, expansions, and enhancements.  

## Simulation Controls

### Command Line Arguments
To run these, use a shortcut to the packaged .exe file and at the end of the target line (in properties editor) add a space and a dash before each argument.

- **VR_Mode**:
  - Loads the simulation in Oculus VR mode rather than flatscreen.
- **Con_Demo**:
  - Loads the simulation directly to the hidden demo level rather than the base tutorial level.
- **Time_Lockout=X**:
  - Enables a timer that reverts simulation to demo level after expired, automatically starts when demo level is not active level.
  - X represents time in minutes of the timer (technically can be a decimal, but avoid).
    - If invalid value, will default to 0 minutes and sim cannot run.

### Controls
**Keyboard:**
![Keyboard Double Control Sets Graphic](Control%20Diagrams/Keyboard%20Control%20Sets.png)

**Xbox-style Controller:**
![Xbox Controller Control Set Graphic](Control%20Diagrams/Xbox%20Controller%20Control%20Layout%20V1.png)

**VR Controller:**
![Xbox Controller Control Set Graphic](Control%20Diagrams/Oculus%20Controller%20Control%20Layout%20Clean%20V2.png)
