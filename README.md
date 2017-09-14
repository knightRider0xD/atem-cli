# atem-cli
Commandline utility for controlling Blackmagic ATEM Switchers based on libqatem.

This tool was designed primarily for use as a way to allow programs written in languages other than C++ to work with ATEM Switchers .

## Current State

### Working:

  * Change Program, Preview, Aux
  * Fade, Cut, Dip transitions
  * Fade to Black
  * Enable/disable/check upstream keyers for next & current transition (in testing)
  * Get Audio Level feed
  * Get/set Channel & Master Volume & Balance
  * Color generator
  * Get/set output resolution/framerate & HD-SDI down-conversion format
  * Save and Clear Settings

### In progress:

  * Enable/disable/check upstream keyers on air
  * Enable/disable/check downstream keyers for next & current transition
  * Enable/disable/check downstream keyers on air

### Todo:

  * Get/set Keyer settings
  * Tally

## Building and Usage

### To build run:
```
qmake  
make
```

### Usage:
```
COMMAND        {PREFIXES}              ARGUMENTS  
────────────────────────────────────────────────────────
ACHNLS         {GET|HELP}   
AINBAL         {GET|SET}               INDEX BALANCE  
AINGAIN        {GET|SET}               INDEX GAIN  
AININFO        {GET}                   INDEX  
AINPEAK        {RESET}                 ALL|[INDEX1,...]  
AINSTATE       {GET|SET}               INDEX STATE  
ALVLS          {ENABLE|DISABLE|GET}    ALL|[INDEX1,...]  
AMSTRGAIN      {GET|SET}               GAIN  
AMSTRLVL       {GET}  
AMSTRPEAK      {RESET}  
AUXSRC         {GET|SET|HELP}          AUXCHNL INDEX  
CLRGENC        {GET|SET}               GENERATOR R G B  
CONN           {START|STOP|GET}  
CUT            {DO}  
DEBUG          {ENABLE|DISABLE|GET} 
FTB            {DO|UNDO|TOGGLE|GET}  
FTBFRAMES      {GET|SET}               INDEX  
FTBFRAMESLEFT  {GET}                   INDEX  
FTBLIVE        {GET}                   INDEX  
ININFO         {GET}                   INDEX  
INNAMEL        {GET|SET}               INDEX NAME  
INNAMES        {GET|SET}               INDEX NAME  
INTYPE         {GET|SET}               INDEX TYPE  
PREV           {GET|SET|HELP}          INDEX  
PROG           {GET|SET|HELP}          INDEX  
SETTINGS       {SAVE|CLEAR}            YES  
TCURRKEY       {GET}                   ALL|INDEX  
TCURRSTYLE     {GET}  
TDIPFRAMES     {GET|SET}               FRAMES  
TDIPSRC        {GET|SET}               SOURCE  
TFRAMES        {GET}                   INDEX  
TMIXFRAMES     {GET|SET}               FRAMES  
TNEXTKEY       {GET|SET}               ALL|INDEX STATE  
TNEXTSTYLE     {GET|SET}               STYLE  
TPOS           {GET|SET}               POSITION  
TPREV          {ENABLE|DISABLE|GET}  
TRANS          {DO}  
VDOWNCONTYPE   {GET|SET}               MODE  
VFMT           {GET|SET|HELP}          FORMAT
```

### Examples:
  * `AINBAL SET 1 0`  
Would set the balance on the audio mixer for input 1 (HDMI/SDI 1 on 1 M/E Production Studio 4K) to 0 (centre)

  * `PROG GET`  
Would get the input number of the currently selected input for PROGRAM

### References:
  * [libqatemcontrol](https://github.com/petersimonsson/libqatemcontrol) for details on the protocol implementation used here.
  * [SKAARHOJ BlackMagic ATEM Switcher Protocol Documentation](http://skaarhoj.com/fileadmin/BMDPROTOCOL.html) for details on the ATEM protocol and expected I/O values used here.
