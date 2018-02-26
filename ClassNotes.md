# Class notes for SCMP 401

## 2-12-18
Presentors this week:

* Doni  
* Miku  
* Tudor

###Doni's Update
Rotary encoders:

* Incrementing  
* Optical

Interrupt function:

* Accounts for high rate of rotation
* Arduino does **not** have a high enough sample rate to accurately record data
* Possible solutions:
 * Change prescaler (?)
 * Planetary gear
 * Use a different arduino (Due)
 * Use a different rotary encoder
 * Suggestions from the class?
 
General Usage:

 * Coach enters email for output (on Raspberry Pi)
 * Swimmer decides to save or not save
 * If save, swimmer enters name, etc.
 * Suggestions:
  * Save options after swim?
  * Barcode tattoos
  * Facial recognition software

###Tudor's Update
Bootstrapping:

* For use when certain statistical tests rely on assumptions that break down
* Tudor's example:
 * Histogramming required GPA's for law schools
 * Current bootstrapping packages do not have intuitive output, not ideal for beginners
* Current research:
 * bootstrap, one-sample statistic
 * StatKey for comparisons, use as a check
* Questions:
 * Usability
* Suggestions:
 * Take survey to gauge usability
 
###Miku's Update

Updates:

* Test workflow
* 19 fields
 * Would like to remove multiple age of child fields

Going forward:

* Distribution of customers on different days
* Date may be enough 
 
 
 
## 2-19-18

### Kara's update

Background:

 * MySQL subtabling
 
What's been done:

 * Looking at database fields
 * Methods of access

 
Accessing the database:

 * Need to access cs3 kenyon server through cslab server
 * Adapting old SQL queries to practice (originally written in PHP)
 * Four relevant fields:
   * IID - bank ID
   * QID - Units of response
   * TimeStamp: Time recorded
 * Writing C++ program to access database
   * Problems with data type matching

Next steps:

 * Create summary tables
   * Site table, bank table
   * Will speed up querying
 * Finish up back-end functions
 * Caching if time permits (?)

Potential issues:

 * Solar data is sharing location with irrelevant information from unrelated project
 * Incorporating a variety of different languages together
   * Translating PHP functions to C++

   
   
### Sam's update

Demonstration of etherium network:

* Job posting w/ etherium
* Life lottery etherium lottery
* CryptoKitties: cats with etherium 

Programming a smart contract:

* Need Geth 
* Private blockchain (public is expensive)
* IDE for smart contract programming (Remix)
* Cost associated with storing information on Etherium network
* Machine code operations measured in Gas

Project Design:

*