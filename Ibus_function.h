
// Create iBus Object
IBusBM ibus;
// Make functions -------------------------------------------------------------------------------------//
// TODO: Move to lib later 
// <----- IBus functions ----->
// Read the number of a given channel and convert to the range provided.
// If the channel is off, return the default value 
int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}


void Debug_plot_raw(int Com){// function to read out the CC array 
   for (byte i = 0; i < BusArray_size; i = i + 1) {
      Serial.print (CC[i]); // for each in Control chan print Value
      Serial.print(" ");    // add space between vars 
   }
    Serial.println(" ");    // addd space and new line
   
}
void Ibus_Read(){// function to Read the IBus and write to the CC "CONTROL CHANNELES" array 
  for (byte i = 0; i < BusArray_size; i = i + 1) {
      CC[i] = ibus.readChannel(i); // attach the ibus to Control chans
  }
}
  
/* Move to Other functions lib or CC Math 
 *  Read the channel and return a boolean value
// My controler has 3 position switchs TODO: Mod this to int or make 3way switch func
bool readSwitch(byte channelInput, bool defaultValue) {
  int intDefaultValue = (defaultValue) ? 100 : 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}*/
