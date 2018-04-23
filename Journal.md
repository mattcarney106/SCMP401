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

## Week of 2-12-08

This week was dedicated to the more computational side of things. Kara will be accessing the database through a c++ file, so the easiest (and most efficient) way for me to take in data from her requests would be to use a cpp file as well. Seeing as I know only Python and C, I anticipate a few hurdles along the way.

After conferring with Kara, the data will most likely be output from the database as a vector. To start, I'd like to start by exploring vectors and their capabilities.

I want to make a plot that can give an estimate to when a solar panel array will pay itself off. I was planning on doing this by having a function that just takes in the name of the site, and then uses the cost of grid electricity per kWh, the power output of the array and calculates how much money has been saved by not having to pay for the power produced by the solar array, and then subtracts that from the initial installation cost.

In order to be efficient with my compilations, I'm going to learn how to use a makefile. This will allow me to compile many different files quickly. I'm going to use the tutorial [here](http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/).

To test out the make file, I made a simple hello world program. I have the following files:

* solar.h: contains the declaration for the helloWorld program  
* solar.cpp: contains the helloWorld function definition and main routine  

Makefiles are made up of "rules", which look like this:

```shell
target: dependencies
	system command
```

The target is the subject of the rule, the dependencies are what is needed for the rule to apply, and the system command is what is executed if the dependencies are met.

I've also organized my files to make the directory a little cleaner. In my main directory, SolarProject, I have a src to house my source code (cpp files, Makefiles, etc), and an include directory to house my header files. Within the src directory, I also have an obj directory which serves as the output for all of the object files created in the compilation process. This means that only the final executable and source files are left. The final file looks like:


```shell
#Defining include directory, compiler, and flags for compiler
IDIR=../include
CC=g++
CFLAGS=-I$(IDIR)

#Defining object directory
ODIR=obj

#Determines all header files (?)
_DEPS=solar.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

#Determines list of obj files that will be created (?)
_OBJ=solar.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

#Compiles all intermediate object files
$(ODIR)/%.o: %.cpp $(DEPS)
        $(CC) -c -o $@ $< $(CFLAGS)

#Makes final executible from all intermediate object files
solar: $(OBJ)
        $(CC) -o $@ $^ $(CFLAGS)
```

Let's pick this apart to make sure we know what's going on here:

```shell
#Defining include directory, compiler, and flags for compiler
IDIR=../include
CC=g++
CFLAGS=-I$(IDIR)

#Defining object directory
ODIR=obj
``` 

The above section defines variables that will go on to tell where the header files are located, what compiler to use when building the scripts, what flags to use for each compile call, and what directory the intermediate object files should be dumped. Here the flags simply indicate to the compiler which directory to search for the header files.

```shell
#Determines all header files (?)
_DEPS=solar.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

#Determines list of obj files that will be created (?)
_OBJ=solar.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))
```

These lines gave me a little more trouble when I was following the tutorial. The command `patsubst` functions essentially like a find and replace. The third argument is the text to search through, the first is the pattern subject to replacement, and the second is what the pattern will be replaced with. In the first part of this excerpt, we search through the text in the variable `_DEPS`. The other two arguments cause a bit of a headache at first glance, but if we think through it, it's a rather clever technique. Setting the pattern as the wildcard and the replacement as include/% means that the command returns all file names common to the `_DEPS` variable and the include/ directory and then adds the prefix include/ to that value. For example, if `solar.h` was found in both include/ and the `_DEPS` variable, the command would return include/solar.h, which is the correct dependency for the compilation to be made. The second section of the code follows the exact same formula, but for the object files.


```shell
#Compiles all intermediate object files
$(ODIR)/%.o: %.cpp $(DEPS)
        $(CC) -c -o $@ $< $(CFLAGS)
```

This section compiles all of the necessary object files to create the final executable. The target here is all object files in the object directory, the dependencies are all of the corresponding c++ files and header files for each object file. The command preforms the preprocessing, compiling, and assembling phases for each object file. 

A few notes on syntax here:

* `$@` is a placeholder for the lefthand side of the colon (target)  
* `$<` is the first item in the dependencies list, which is all dependencies here

The final step is to link all object files into one executable:

```shell
#Makes final executible from all intermediate object files
solar: $(OBJ)
        $(CC) -o $@ $^ $(CFLAGS)
```

This takes all the object files found in the object directory and links them together to make the `solar` executable.

## Week of 2-19-08

This week was rather slow as I had two large projects due during the week that sucked a lot of my time. Fortunately, this means that next week I'll have significantly more time to execute the ideas I came up with in preparation for my presentation. 

What I did accomplish this week was perfecting my Makefile to be as general as possible to the solar project. This means that I can now add any .cpp or .h files to my source directories and they will be automatically compiled without needing to add a rule for them. Secondly, I've started coming up with some ideas for how to model the efficiency drops after speaking with a fellow physics major who presented on solar cells for her senior exercise. I'm starting to feel like a real developer! Next steps will include creating a prototype efficiency model coded into my software package. Finally, I'll be starting some of the long-term analyses in which I anticipate incorporating downsampling routines to account for the large amount of data.

## Week of 3-26-18

Unfortunately, I've missed a few journal entries and I'll be adding them in retroactively over the next few days. I know this is suboptimal to writing one consistently each week, but I figure it's better to have a record for documentation purposes, if nothing else. 

This week I finished the toy model for the projection, which takes in a vector for the time series of watt values for a solar site and returns a vector of the amount of the initial cost left unpaid for each hour.

```cpp
 vector<double> amount_unpaid(double initial_cost, vector<double> money_saved)
 81 {
 82   vector<double> amount_unpaid(money_saved.size());
 83   double current_unpaid = initial_cost;
 84   for(int i=0;i<amount_unpaid.size();i++)
 85   {
 86     amount_unpaid[i] = current_unpaid - money_saved[i];
 87     current_unpaid = amount_unpaid[i];
 88   }
 89   return amount_unpaid;
 90 }
```

I was able to get the electricity rates from the BEL website, so these should be accurate.

```cpp
 /* Takes in powerOutput and returns
 26    The BEL rate in USD per kWhr
 27 */
 28 double CalcBELRate(double powerOutput)
 29 { 
 30   double rate;
 31   if(powerOutput >= 0.0 && powerOutput < 51.0){
 32     rate = 0.30;
 33   }else if(powerOutput >= 51.0 && powerOutput < 201.0){
 34     rate = 0.36;
 35   }else if(powerOutput >= 201.0){
 36     rate = 0.40;
 37   }else{ 
 38     cout << "INVALID POWER OUTPUT\n";
 39   }
 40   
 41   return rate;
 42 }
```

The next step will be to include an extrapolation routine to give a projected pay-off date.

## Week of 4-2-18

These next two weeks will be tough since comps and honors fall on the same two weeks. Since I won't have much time to sit down for a few hours at a time, I thought my time would be best spent researching the pros and cons of the possible extrapolation routines. 

GSL

 * Written in C, so familiar
 * Have used interpolation methods in the past
 * somewhat esoteric and antiquated
 * quite a few dependencies

Writing my own

 * Can use experience with GSL
 * Since the payoff curve is relatively linear, will probably only need linear extrapolation

Additionally, I've made plans to meet with my project partners to discuss how our codes will be implemented together. I'm very excited to spend significantly more of my time on the project in the next few weeks. 

##Week of 4-16-18

I started off the week the APS April Meeting conference where I attended some talks on machine learning and other advanced computational techniques that I thought would be relevant to our capstone seminar. As for work, I've been attempting to connect my and Kara's code so that I can make SQL queries to get updated data.

Unfortunately, I've run into some serious problems creating the framework to run the connection code. Kara's code was developed on the cslab server, which already has both the MySQL and MySQL c++ connection libraries. I do not have access to the server and until I do, I thought it best that I had a similar environment on which to develop. I was able to download the MySQL software using the GUI installer provided on their website. Kara's code is also dependent on the MySQL c++ connection code, which has been trickier to get working. 

I use the Homebrew package manager for most of my installs so I wanted to keep everything consistent. I got the following error when trying to install mysql-connector-c++:

```console
Matthews-MacBook-Pro-4:~ matthewcarney$ brew install mysql-connector-c++
Warning: You are using OS X 10.13.
We do not provide support for this pre-release version.
You may encounter build failures or other breakages.
Please create pull-requests instead of filing issues.
==> Installing dependencies for mysql-connector-c++: cmake, mysql, boost
==> Installing mysql-connector-c++ dependency: cmake
==> Downloading https://cmake.org/files/v3.6/cmake-3.6.0.tar.gz
Already downloaded: /Users/matthewcarney/Library/Caches/Homebrew/cmake-3.6.0.tar.gz
==> Downloading https://gitlab.kitware.com/cmake/cmake/merge_requests/34.patch
Already downloaded: /Users/matthewcarney/Library/Caches/Homebrew/cmake--patch-6d47140ebb65c045d9eee2c363aa22e53973a54b9bcdc11ef7b622c97419999f.patch
Error: SHA256 mismatch
Expected: 6d47140ebb65c045d9eee2c363aa22e53973a54b9bcdc11ef7b622c97419999f
Actual: 3228bf0cd769012340a730fc050339bd57639678734f99f0768a504f8368e777
Archive: /Users/matthewcarney/Library/Caches/Homebrew/cmake--patch-6d47140ebb65c045d9eee2c363aa22e53973a54b9bcdc11ef7b622c97419999f.patch
To retry an incomplete download, remove the file above.
``` 

This is apparently a problem with an outdated homebrew, so I tried a brew update, which resulted in a permissions error for the directory usr/local. Unfortunately, even a sudo chown command does not remedy the issue with the current version of macOS. This  can be solved by uninstalling and reinstalling homebrew through cURL:

```console
matthewcarney$ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/uninstall)"
```

But alas, we run into another error claiming that HTTPS protocol is not supported by libcurl or at least not enabled:

```console
curl: (1) Protocol "https" not supported or disabled in libcurl
```

This has been a huge time suck. I've tried uninstalling curl and reinstalling,

```console
brew install curl --with-openssl --with-nghttp2
```
specifying to homebrew to configure the installation with both openssl and http, but I end up with the same error as above. I tried downloading the source code for the most recent version of curl (7.59.0), and explicitely including the dependency in the configure command, and then installing.

```console
matthewcarney$ ./configure --prefix=/usr/local/curl --with-darwinssl --with-ssl=/usr/local/opt/openssl --disable-werror --disable-warnings
matthewcarney$ make -j
matthewcarney$ sudo make -j install
```

I did a which curl to determine which version of curl was being used and it turned out that I was using the system installed curl. After changing the ruby command to the correct version (usr/local/curl/bin/curl), I was successfully able to uninstall Homebrew! Ironically, this uninstalled the version of curl that I installed so I had to reinstall that and then successfully installed the newest version of homebrew.

I understand that this is quite the rabbit hole I've gone down but I've learned quite a lot about package management and installation which I think will make creating a cohesive, concise solar package much easier.

Incredibly, after all this, the brew install mysql-connector-c++ installed successfully. I had to install one more package, but now I'm relatively confident that all dependencies are accounted for. But, as all coding goes, now I have another error which I believe is a problem with my makefile.

Turns out it was just a problem with trying to compile two programs into one executable. This was fixed by separating the two.

```console
USER= carneym

#Defining include directory, compiler, and flags for compiler
IDIR=../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11  -Wno-deprecated-declarations

#Defining libary directories
LIBDIR=/usr/local/lib

LIBS= -lmysqlcppconn

#Defining object directory
ODIR=obj

#Compiling Kara's code
#Determines all header files
_DEPS=site.h sites.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

#Determines list of obj files that will be created
_OBJ=TestDBquery.o site.o sites.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

all: TestDBquery solar

#Compiles all intermediate object files
$(ODIR)/%.o: %.cpp $(DEPS)
        $(CC) -c -o $@ $< $(CFLAGS) 

#Makes final executible from all intermediate object files
TestDBquery: $(OBJ)
        $(CC) -o $@ $^ $(CFLAGS) $(LIBS)

#Compiling my code
_DEPS=solar.h site.h sites.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=solar.o site.o sites.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
        $(CC) -c -o $@ $< $(CFLAGS) 

solar: $(OBJ)
        $(CC) -o $@ $^ $(CFLAGS) $(LIBS)
```
