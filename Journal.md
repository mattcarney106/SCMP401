# Belize Solar Project Journal 

## Week of 2-05-18

This past week I worked with Jensen and Kara on a presentation going over the outline, project components, and specific tasks. We presented to the class and fielded suggestions from our classmates. These suggestions are available on Google Docs.

### 2-07-18

Met with Professor Skon to discuss data analysis prospects:

Big Ideas:

1. Cost Analysis  
  * Missing data (optimistic vs pessimistic)  
  * Pessimistic: Assume every time data is missing, the solar panel is not functioning (gap is not due to network failure)  
  * Determine what people want to see to inform data analytics  
  * Modeling efficiency(?)  
    * Different ways the efficiency can change  
      * Corrosion  
      * Dirt  
    * Resistance change effect on efficiency  


Logistics:

1. Language choice:

* Rank language preferences individually, then compare  
* C++ standard template library

### 2-09-18

Today I decided to do some research into the basics of solar panel electronics. Here are some notes:

There are essentially two kinds of solar panels: photovoltaic and photothermal. The solar panels that have been installed in Belize are photovoltaic, so I'll be looking into those. 

#### Photovoltaic solar panels

Note: much of this material was gained from the [wikipedia page on solar panels](https://en.wikipedia.org/wiki/Solar_panel)

Photovoltaic solar panels rely on a process very similar to the photoelectric effect, a phenomenon that I've come across many times in my physics courses. The photoelectric effect occurs when a photon is incident on a material, and collides with an atom in the material. The energy from the photon is absorbed by an electron in the atom, ejecting it from the material. The *photovoltaic effect*, however, is slightly different. When the energy of the incident photon is less than the ionization energy of the atom, but larger than the energy gap between the electron and a higher energy level, the electron jumps to the higher energy level, further separating the negatively charged electron from the positively charged nucleus, thus resulting in an electric potential.

##### Efficiency

Since one of my prospective tasks for the data analysis portion of the project will be modeling the efficiency of the solar panels, it will be important for me to research common methods for computing solar efficiency and how one would go about modeling it.

The efficiency of a photovoltaic cell is given by 

eta = P_out/P_in = P_max/(E * A_cel)

where P_out is the output power of the solar cell, E is the radiation flux incident on the panel, and A is the area of the cell. Note that this expression assumes ideal conditions and should be used as an upper bound on the efficiency of the cell. If I were to model the efficiency of the Belize solar cells, I could use this as a sort of goal or target efficiency.
