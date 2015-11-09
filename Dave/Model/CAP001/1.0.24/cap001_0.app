<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="CAP001" description="This app is used to measure the &#xA; period and duty cycle &#xA; of input signal.&#xA; Please connect input signal &#xA; to both input duty and &#xA; input period virtual signals." descriptionURL="/doc/html/group___c_a_p001_app.html" URI="http://www.infineon.com/1.0.24/app/cap001/0">
  <provided xsi:type="ResourceModel:VirtualSignal" name="Global" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_globalsignal_vs" requiredSignalResource="slice/global_signal">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Timer Conctenation Output" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_output_concatenation_vs" requiredSignalResource="slice1/concat_bus_out" canExpose="false">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name=" Timer Concatenation Input" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_input_concatenation_vs" requiredSignalResource="slice/concat_bus_in" canExpose="false">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Period Capture Interrupt" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_periodcapture_interrupt_vs" requiredSignalResource="slice/e0as">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Duty Capture Interrupt" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_dutycapture_interrupt_vs" requiredSignalResource="slice/e1as">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Timer Concatenation Period Capture Interrupt" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_periodcapture_tc_interrupt_vs" requiredSignalResource="slice1/e0as">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Timer Concatenation Duty Capture Interrupt" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_dutycapture_tc_interrupt_vs" requiredSignalResource="slice1/e1as">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Input Period" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_input_period_signal_vs" requiredSignalResource="slice/gp0_unsync">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name=" Input Duty" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_input_duty_signal_vs" requiredSignalResource="slice/gp1_unsync">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Timer Concatenation Input Period" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_tc_input_period_signal_vs" requiredSignalResource="slice1/gp0_unsync">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Timer Concatenation Input Duty" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_tc_input_duty_signal_vs" requiredSignalResource="slice1/gp1_unsync">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Overwrite Capture value" evalFunction=" &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/tc/ccs&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/tc/ccs&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwoverwrite" downWardmappedList="//@consumed.25" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This decides whether to overwrite the previous captured value or ignore the new value in case of previous value is not read.</toolTipHelpDescription>
    <item name="Enable" evalFunction=" &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;                var Res = SCM.getResource(&quot;slice/tc/ccs&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }else if(value === 0){&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }            &#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;                var Res = SCM.getResource(&quot;slice/tc/ccs&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value == -1) {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(currentResource,0);                &#xD;&#xA;              }else if(value == 1){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwoverwrite/0" downWardmappedList="//@consumed.25" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Capture is always done even if the previous captured value is not read back. Setting this bit might lose captured values if not read immediately.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Low Pass Filter" evalFunction=" &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwlpf" downWardmappedList="//@consumed.17">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows user to select the low pass filter configuration to suppress the noise in the input signal. </toolTipHelpDescription>
    <item name="No" evalFunction="             &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;);&#xD;&#xA;              var Res1 = SCM.getResource(&quot;slice/ins/lpf1m&quot;);        &#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,0);        &#xD;&#xA;                SCM.setIntValue(Res1,0);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;                SCM.setIntValue(Res1,0);&#xD;&#xA;              }        &#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value === 0 ) { &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwlpf/0" downWardmappedList="//@consumed.17 //@consumed.18" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>No LPF is required.</toolTipHelpDescription>
    </item>
    <item name="3 CCU4 Clock cycles" evalFunction="   &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;);&#xD;&#xA;              var Res1 = SCM.getResource(&quot;slice/ins/lpf1m&quot;);        &#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);        &#xD;&#xA;                SCM.setIntValue(Res1,1);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;                SCM.setIntValue(Res1,0);&#xD;&#xA;              }        &#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value === 1 ) { &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwlpf/1" downWardmappedList="//@consumed.17 //@consumed.18" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Signal is captured only after signal value remains stable for 3 consecutive clock cycles.</toolTipHelpDescription>
    </item>
    <item name="5 CCU4 Clock cycles" evalFunction="   &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;);&#xD;&#xA;              var Res1 = SCM.getResource(&quot;slice/ins/lpf1m&quot;);        &#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,2);        &#xD;&#xA;                SCM.setIntValue(Res1,2);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;                SCM.setIntValue(Res1,0);&#xD;&#xA;              }        &#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value === 2 ) { &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwlpf/2" downWardmappedList="//@consumed.17 //@consumed.18" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Signal is captured only after signal value remains stable for 5 consecutive clock cycles.</toolTipHelpDescription>
    </item>
    <item name="7 CCU4 Clock cycles" evalFunction="   &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;);&#xD;&#xA;              var Res1 = SCM.getResource(&quot;slice/ins/lpf1m&quot;);        &#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,3);        &#xD;&#xA;                SCM.setIntValue(Res1,3);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;                SCM.setIntValue(Res1,0);&#xD;&#xA;              }        &#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/lpf0m&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value === 3 ) { &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwlpf/3" downWardmappedList="//@consumed.17 //@consumed.18" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Signal is captured only after signal value remains stable for 7 consecutive clock cycles.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Period Capture" evalFunction=" &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/ev0em&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/ev0em&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwperiod" downWardmappedList="//@consumed.19">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows user to select the edge for period capture - Rise to Rise or Fall to Fall</toolTipHelpDescription>
    <item name="Rise-to-Rise" evalFunction="   &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/ev0em&quot;);  &#xD;&#xA;              var Res1 = SCM.getResource(&quot;slice/ins/ev1em&quot;);  &#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res1,2);&#xD;&#xA;                SCM.setIntValue(Res,1);     &#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res1,0); &#xD;&#xA;                SCM.setIntValue(Res,0); &#xD;&#xA;              }        &#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/ev0em&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value == 1 ) { &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 || value === 0 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwperiod/0" downWardmappedList="//@consumed.20 //@consumed.19" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Period of the input signal is time between Rising edge to Rising edge</toolTipHelpDescription>
    </item>
    <item name="Fall-to-Fall" evalFunction="   &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/ev0em&quot;);&#xD;&#xA;              var Res1 = SCM.getResource(&quot;slice/ins/ev1em&quot;);    &#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res1,1);&#xD;&#xA;                SCM.setIntValue(Res,2);         &#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;&#xD;&#xA;                SCM.setIntValue(Res1,0); &#xD;&#xA;                SCM.setIntValue(Res,0); &#xD;&#xA;              }        &#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;slice/ins/ev0em&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              if (value == 2 ) { &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwperiod/1" downWardmappedList="//@consumed.20 //@consumed.19" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Period of the input signal is time between Falling edge to Falling edge</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Duty Capture" evalFunction=" &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_tempduty&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_tempduty&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwduty" downWardmappedList="//@consumed.4">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <toolTipHelpDescription>This allows user to select the level of the ON time - Rise to Fall or Fall to Rise</toolTipHelpDescription>
    <item name="Rise-to-Fall" evalFunction=" &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_tempduty&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;              &#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_tempduty&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if(value == 1 || value == -1){ &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else{&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwduty/0" downWardmappedList="//@consumed.4" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>ON time of the signal is active high. Duty cycle is the time between Rising edge to Falling edge.</toolTipHelpDescription>
    </item>
    <item name="Fall-to-Rise" evalFunction=" &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_tempduty&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,2);&#xD;&#xA;              }&#xD;&#xA;              &#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_tempduty&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if(value == 2){ &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else{&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwduty/1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>ON time of the signal is active low. Duty cycle is the time between Falling edge to Rising edge.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="CCU4 clock" evalFunction="   &#xD;&#xA;        function ForwardMapping(){&#xD;&#xA;            var Res2 = SCM.getResource(&quot;ccu4globalapp/ccu4global_irclock&quot;);          &#xD;&#xA;            var Clock = SCM.getIntValue(Res2);&#xD;&#xA;        }&#xD;&#xA;&#xD;&#xA;        function BackwardMapping(){&#xD;&#xA;            var Res2 = SCM.getResource(&quot;ccu4globalapp/ccu4global_irclock&quot;);          &#xD;&#xA;            var Clock = SCM.getIntValue(Res2);&#xD;&#xA;            SCM.setDoubleValue(currentResource,Clock); &#xD;&#xA;        }&#xD;&#xA;        " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_irclock" maxValue="78" minValue="1">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <toolTipHelpDescription>This saves the CCU clock frequency.</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="CCU4 clock resolution" evalFunction="   &#xD;&#xA;        function ForwardMapping(){&#xD;&#xA;            var Res2 = SCM.getResource(&quot;ccu4globalapp/ccu4global_irclock&quot;);          &#xD;&#xA;            var Clock = SCM.getIntValue(Res2);&#xD;&#xA;            var XMC1xxx=SCM.getSoftwareId().substring(0,1).compareTo(&quot;1&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;if(Clock == -1){&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;if(XMC1xxx == 0){Clock = 32;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;else {Clock = 120;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;            var clkDiv = (1000 /Clock);      &#xD;&#xA;&#xD;&#xA;            var value2 = SCM.getDoubleValue(currentResource);&#xD;&#xA;            var tempRes = SCM.getResource(&quot;cap001_tempresolution&quot;);&#xD;&#xA; &#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;if(value2 == 0)&#xD;&#xA;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;if(XMC1xxx == 0){value2 = 32;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;else {value2 = 20;}&#xD;&#xA;&#x9;&#x9;&#x9;}&#xD;&#xA;&#xD;&#xA;            SCM.setDoubleValue(tempRes,value2);&#xD;&#xA;            var Res3 = SCM.getResource(&quot;slice/psc/psiv&quot;);  &#xD;&#xA;&#xD;&#xA; &#x9;&#x9;&#x9;if(value2>=clkDiv)&#xD;&#xA;            var Divider = (value2) / clkDiv;&#xD;&#xA;&#x9;&#x9;&#x9;else&#xD;&#xA;            var Divider = 1;&#xD;&#xA;&#xD;&#xA;            var Prescalar = Math.floor( Math.log(Divider) / Math.log( 2 ) );          &#xD;&#xA;            SCM.setIntValue(Res3, Prescalar); &#xD;&#xA;      }&#xD;&#xA;&#xD;&#xA;        function BackwardMapping(){&#xD;&#xA;            var tempRes = SCM.getResource(&quot;cap001_tempresolution&quot;);&#xD;&#xA;            var value = SCM.getDoubleValue(tempRes);&#xD;&#xA;            var Res2 = SCM.getResource(&quot;ccu4globalapp/ccu4global_irclock&quot;);          &#xD;&#xA;            var Clock = SCM.getIntValue(Res2);&#xD;&#xA;            SCM.setDoubleValue(currentResource,value); &#xD;&#xA;&#xD;&#xA;            var clkDiv = (1000 /Clock); &#xD;&#xA;            var res_max = Math.ceil(clkDiv*32768);&#xD;&#xA;            var res_min = Math.ceil(clkDiv);&#xD;&#xA;            SCM.setMinMaxValue(currentResource,res_min,res_max,1);&#xD;&#xA;&#xD;&#xA;        }&#xD;&#xA;        " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_irwresolution" downWardmappedList="//@consumed.5 //@consumed.28" maxValue="42aab" minValue="9">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="14"/>
    <toolTipHelpDescription>This allows a user to input resolution for CCU4 clock. This decides the clock divider factor for the CCU4 slice.</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Selected Resolution" evalFunction="  &#xD;&#xA;        function ForwardMapping(){&#xD;&#xA;            var Res3 = SCM.getResource(&quot;slice/psc/psiv&quot;);&#xD;&#xA;            var value3 = SCM.getIntValue(Res3); &#xD;&#xA;            var Res2 = SCM.getResource(&quot;ccu4globalapp/ccu4global_irclock&quot;);          &#xD;&#xA;            var Clock = SCM.getIntValue(Res2);         &#xD;&#xA;        }&#xD;&#xA;        function BackwardMapping(){&#xD;&#xA;              var Res2 = SCM.getResource(&quot;ccu4globalapp/ccu4global_irclock&quot;);          &#xD;&#xA;              var Clock = SCM.getIntValue(Res2);&#xD;&#xA;              var XMC1xxx=SCM.getSoftwareId().substring(0,1).compareTo(&quot;1&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;  if(Clock == -1){&#xD;&#xA;&#x9;&#x9;&#x9;&#x9; if(XMC1xxx == 0){Clock = 32;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9; else {Clock = 120;}&#xD;&#xA;&#x9;&#x9;&#x9;  }&#xD;&#xA;              var clkDiv = (1000 /Clock); &#xD;&#xA;     &#xD;&#xA;              var Res_2 = SCM.getResource(&quot;cap001_tempresolution&quot;);&#xD;&#xA;              var value2 = SCM.getDoubleValue(Res_2);&#xD;&#xA;&#xD;&#xA; &#x9;&#x9;&#x9;  if(value2>=clkDiv)&#xD;&#xA;              var Divider = (value2) / clkDiv;&#xD;&#xA;&#x9;&#x9;&#x9;  else&#xD;&#xA;              var Divider = 1;&#xD;&#xA;&#xD;&#xA;              var Prescalar = Math.floor( Math.log(Divider) / Math.log( 2 ) );          &#xD;&#xA;              var temp = 0;   &#xD;&#xA;              if(Prescalar > 15) {&#xD;&#xA;                temp = 0;&#xD;&#xA;              }&#xD;&#xA;              else{           &#xD;&#xA;                temp = clkDiv * (1 &lt;&lt; Prescalar);&#xD;&#xA;              }&#xD;&#xA;              SCM.setDoubleValue(currentResource, temp);&#xD;&#xA;&#xD;&#xA;              var res_max = Math.ceil(clkDiv*32768);&#xD;&#xA;              var res_min = Math.floor(clkDiv);&#xD;&#xA;              SCM.setMinMaxValue(currentResource,res_min,res_max,1);&#xD;&#xA;&#xD;&#xA;        }&#xD;&#xA; " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_irselresolution" maxValue="42aab" minValue="8">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="14"/>
    <localValue xsi:type="ResourceModel:StringValue" value="14"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="4030aaaaaaaaaaab"/>
    <toolTipHelpDescription>This is the closest possible resolution value (non-editable)</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Selected Prescalar value" evalFunction="  &#xD;&#xA;        function ForwardMapping(){&#xD;&#xA;            var Res3 = SCM.getResource(&quot;slice/psc/psiv&quot;);&#xD;&#xA;            var value3 = SCM.getIntValue(Res3); &#xD;&#xA;            var Res2 = SCM.getResource(&quot;ccu4globalapp/ccu4global_irclock&quot;);          &#xD;&#xA;            var Clock = SCM.getIntValue(Res2);         &#xD;&#xA;        }&#xD;&#xA;        function BackwardMapping(){&#xD;&#xA;              var Res2 = SCM.getResource(&quot;ccu4globalapp/ccu4global_irclock&quot;);          &#xD;&#xA;              var Clock = SCM.getIntValue(Res2);&#xD;&#xA;              var XMC1xxx=SCM.getSoftwareId().substring(0,1).compareTo(&quot;1&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;  if(Clock == -1){&#xD;&#xA;&#x9;&#x9;&#x9;&#x9; if(XMC1xxx == 0){Clock = 32;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9; else {Clock = 120;}&#xD;&#xA;&#x9;&#x9;&#x9;  }&#xD;&#xA;&#xD;&#xA;              var clkDiv = (1000 /Clock); &#xD;&#xA;     &#xD;&#xA;              var Res_2 = SCM.getResource(&quot;cap001_tempresolution&quot;);&#xD;&#xA;              var value2 = SCM.getDoubleValue(Res_2);&#xD;&#xA;&#xD;&#xA; &#x9;&#x9;&#x9;  if(value2>=clkDiv)&#xD;&#xA;              var Divider = (value2) / clkDiv;&#xD;&#xA;&#x9;&#x9;&#x9;  else&#xD;&#xA;              var Divider = 1;&#xD;&#xA;&#xD;&#xA;              var Prescalar = 0;&#xD;&#xA;              Prescalar = Math.floor( Math.log(Divider) / Math.log( 2 ) );          &#xD;&#xA;              SCM.setIntValue(currentResource, Prescalar);&#xD;&#xA;        }&#xD;&#xA; " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_irprescalar" maxValue="F" minValue="0">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <localValue xsi:type="ResourceModel:StringValue" value="1"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <toolTipHelpDescription>This is the prescalar value</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Max Frequency" evalFunction="&#xD;&#xA;        function ForwardMapping(){&#xD;&#xA;              var Res2 = SCM.getResource(&quot;ccu4globalapp/ccu4global_irclock&quot;);          &#xD;&#xA;              var Clock = SCM.getIntValue(Res2);&#xD;&#xA;        }&#xD;&#xA;&#xD;&#xA;        function BackwardMapping(){&#xD;&#xA;              var Res2 = SCM.getResource(&quot;ccu4globalapp/ccu4global_irclock&quot;);          &#xD;&#xA;              var Clock = SCM.getIntValue(Res2);&#xD;&#xA;              var XMC1xxx=SCM.getSoftwareId().substring(0,1).compareTo(&quot;1&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;  if(Clock == -1){&#xD;&#xA;&#x9;&#x9;&#x9;&#x9; if(XMC1xxx == 0){Clock = 32;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9; else {Clock = 120;}&#xD;&#xA;&#x9;&#x9;&#x9;  }&#xD;&#xA;              var clkDiv = (1000 /Clock); &#xD;&#xA;     &#xD;&#xA;              var Res_2 = SCM.getResource(&quot;cap001_tempresolution&quot;);&#xD;&#xA;              var value2 = SCM.getDoubleValue(Res_2);&#xD;&#xA;&#xD;&#xA; &#x9;&#x9;&#x9;  if(value2>=clkDiv)&#xD;&#xA;              var Divider = (value2) / clkDiv;&#xD;&#xA;&#x9;&#x9;&#x9;  else&#xD;&#xA;              var Divider = 1;&#xD;&#xA;&#xD;&#xA;              var Prescalar = Math.floor( Math.log(Divider) / Math.log( 2 ) );          &#xD;&#xA;              var temp = 0;   &#xD;&#xA;              if(Prescalar > 15) {&#xD;&#xA;                temp = 0;&#xD;&#xA;              }&#xD;&#xA;              else{           &#xD;&#xA;                temp = Clock >> (Prescalar + 1);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;temp = temp * 1000000;&#xD;&#xA;              }&#xD;&#xA;             SCM.setDoubleValue(currentResource,temp);&#xD;&#xA;&#xD;&#xA;        }" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_maxfreq" maxValue="3938700" minValue="1">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="100"/>
    <localValue xsi:type="ResourceModel:StringValue" value="100"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1c9c380"/>
    <toolTipHelpDescription>This is the maximum frequency of the input capture signal in hertz. Please enter the max frequency less than possible max frequency.</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Min Frequency" evalFunction="&#xD;&#xA;        function ForwardMapping(){&#xD;&#xA;          var freq = SCM.getDoubleValue(currentResource);&#xD;&#xA;          var tempRes = SCM.getResource(&quot;cap001_tempminfreq&quot;);&#xD;&#xA;          SCM.setDoubleValue(tempRes, freq);&#xD;&#xA;        }&#xD;&#xA;&#xD;&#xA;        function BackwardMapping(){&#xD;&#xA;            var tempRes = SCM.getResource(&quot;cap001_tempminfreq&quot;);&#xD;&#xA;            var value = SCM.getDoubleValue(tempRes);&#xD;&#xA;            var Res2 = SCM.getResource(&quot;ccu4globalapp/ccu4global_irclock&quot;);          &#xD;&#xA;            var Clock = SCM.getIntValue(Res2);&#xD;&#xA;            var XMC1xxx=SCM.getSoftwareId().substring(0,1).compareTo(&quot;1&quot;);&#xD;&#xA;&#xD;&#xA;            SCM.setDoubleValue(currentResource,value);&#xD;&#xA;&#xD;&#xA;&#x9;&#x9;   if(Clock == -1){&#xD;&#xA;&#x9;&#x9;&#x9; if(XMC1xxx == 0){Clock = 32;}&#xD;&#xA;&#x9;&#x9;&#x9; else {Clock = 120;}&#xD;&#xA;&#x9;&#x9;     }&#xD;&#xA;           var res_max = Math.floor(Clock/2);&#xD;&#xA;&#x9;       res_max = Math.floor(res_max * 1000000);&#xD;&#xA;           var res_min = 0;&#xD;&#xA;           SCM.setMinMaxValue(currentResource,res_min,res_max,1);&#xD;&#xA; &#xD;&#xA;&#xD;&#xA;        }" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_minfreq" downWardmappedList="//@consumed.6" maxValue="3938700" minValue="0">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="7D0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="7D0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="7d0"/>
    <toolTipHelpDescription>This is the minimum frequency of the input capture signal in hertz.
 In case Timer concatenation is selected then, use signals prefixed with Timer Concatenation for connection. </toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Timer concatenation" evalFunction="&#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;            var Res3 = SCM.getResource(&quot;slice/psc/psiv&quot;);&#xD;&#xA;            var value3 = SCM.getIntValue(Res3);&#xD;&#xA;            var Res2 = SCM.getResource(&quot;ccu4globalapp/ccu4global_irclock&quot;);          &#xD;&#xA;            var Clock = SCM.getIntValue(Res2);&#xD;&#xA;            var Res4 = SCM.getResource(&quot;cap001_tempminfreq&quot;);          &#xD;&#xA;            var value4 = SCM.getIntValue(Res4);            &#xD;&#xA;          }&#xD;&#xA;&#xD;&#xA;          function BackwardMapping()&#xD;&#xA;          {&#xD;&#xA;            var Res  = SCM.getResource(&quot;cap001_irselresolution&quot;);&#xD;&#xA;            var resolution = SCM.getDoubleValue(Res);&#xD;&#xA;            var Res1 = SCM.getResource(&quot;cap001_minfreq&quot;);&#xD;&#xA;            var freq = SCM.getDoubleValue(Res1);&#xD;&#xA;            var count = 0.0;&#xD;&#xA;            var timermode = 0;&#xD;&#xA;            count = 9 - ((Math.log(freq) + Math.log(resolution))/Math.log(10));&#xD;&#xA;            count = count*1000;&#xD;&#xA;            if(count &lt; 4816.4733037652497077843543687786)&#xD;&#xA;            {&#xD;&#xA;              timermode = 0;&#xD;&#xA;            }&#xD;&#xA;            else &#xD;&#xA;            {&#xD;&#xA;              timermode = 1;&#xD;&#xA;            }&#xD;&#xA;            SCM.setDoubleValue(currentResource, timermode);&#xD;&#xA;          }&#xD;&#xA;         " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_irtimerconcat" maxValue="2" minValue="0">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>Non-editable field. It displays whether timer concatenation is enabled or not</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Timer Mode" evalFunction=" &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_temptimer&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_temptimer&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwtimermode" downWardmappedList="//@consumed.1">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <toolTipHelpDescription>This allows user to select the Timer mode used for capturing period and duty cycle</toolTipHelpDescription>
    <item name="Floating Prescalar" evalFunction=" &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_temptimer&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;              &#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_temptimer&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if(value == 1 || value == -1){ &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else{&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwtimermode/0" downWardmappedList="//@consumed.1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>In this mode, timer prescalar value is dynamically changed.It increases&#xD;
the capture range.</toolTipHelpDescription>
    </item>
    <item name="Timer Concatenation" evalFunction=" &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_temptimer&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,2);&#xD;&#xA;              }&#xD;&#xA;              &#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_temptimer&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if(value == 2){ &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else{&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwtimermode/1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>In this mode, one additional slice is required.Two slices are&#xD;
concatenated to increase the capture range.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:StringParameter" name="Timer Configuration " evalFunction="&#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;            var Res3 = SCM.getResource(&quot;slice/psc/psiv&quot;);&#xD;&#xA;            var value3 = SCM.getIntValue(Res3);&#xD;&#xA;            var Res2 = SCM.getResource(&quot;ccu4globalapp/ccu4global_irclock&quot;);          &#xD;&#xA;            var Clock = SCM.getIntValue(Res2);&#xD;&#xA;            var Res4 = SCM.getResource(&quot;cap001_tempminfreq&quot;);          &#xD;&#xA;            var value4 = SCM.getIntValue(Res4);            &#xD;&#xA;          }&#xD;&#xA;&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;            var Res  = SCM.getResource(&quot;cap001_irtimerconcat&quot;);&#xD;&#xA;            var timermode = SCM.getDoubleValue(Res);&#xD;&#xA;            if(timermode == 0){&#xD;&#xA;               SCM.setStringValue(currentResource, &quot;NORMAL PRESCALAR&quot;);&#xD;&#xA;            }&#xD;&#xA;            else if(timermode == 1){&#xD;&#xA;               SCM.setStringValue(currentResource, &quot;TIMER CONCATENATION&quot;);&#xD;&#xA;            }&#xD;&#xA;            else if(timermode == 2){&#xD;&#xA;               SCM.setStringValue(currentResource, &quot;FLOATING PRESCALAR&quot;);&#xD;&#xA;            }&#xD;&#xA;          }&#xD;&#xA;         " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_srtimersetting">
    <defaultValue xsi:type="ResourceModel:StringValue" value="NORMAL PRESCALAR"/>
    <localValue xsi:type="ResourceModel:StringValue" value="NORMAL PRESCALAR"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="NORMAL PRESCALAR"/>
    <toolTipHelpDescription>Non-editable field. It displays whether normal prescalar, floating prescalar or timer concatenation feature is used to satisfy the required resolution and min, max frequency requirements.</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Start" evalFunction=" &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_tempstart&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_tempstart&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwstart" downWardmappedList="//@consumed.3" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows user to configure whether this app should be started&#xD;
during initialization. The starting of an App means CCU in capture mode and ready to capture the Input Signal.&#xD;
Input pins are configured after initialization of this pin.&#xD;
So, there might be some delay till input signal reaches the CCU4.</toolTipHelpDescription>
    <item name="Start During initialization" evalFunction=" &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_tempstart&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;              else{&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;              &#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_tempstart&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if(value == 1){ &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else if(value == -1){ &#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else{&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwstart/0" downWardmappedList="//@consumed.3" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Start the capture of Input Signal during init sequence. Please make sure that there is no dependency on other apps or on the pin configurations.&#xD;
If there is dependency, it is recommended not to start App during Initialisation.&#xD;
</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Capture Interrupt" evalFunction=" &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_tempcapture&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_tempcapture&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res); &#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwcapture" downWardmappedList="//@consumed.2" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows user to configure whether capture interrupt&#xD;
to be enabled during initialization.</toolTipHelpDescription>
    <item name="Enable at initialization" evalFunction=" &#xD;&#xA;          function ForwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_tempcapture&quot;); &#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              if(value == 1){&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;              else{&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }              &#xD;&#xA;          }&#xD;&#xA;          function BackwardMapping(){&#xD;&#xA;              var Res = SCM.getResource(&quot;cap001_tempcapture&quot;); &#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if(value == 1){ &#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else if(value == -1){ &#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else{&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;          }&#xD;&#xA;               " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_erwcapture/0" downWardmappedList="//@consumed.2" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Enable Capture interrupt at initialization.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function initializes the CCU4_CCy slice with the configured parameters to capture the period and duty cycle of input signal." URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_init" APIName="CAP001_Init">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will reset the App." URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_deinit" APIName="CAP001_Deinit">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will read the capture registers." URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_getcapregs" APIName="CAP001_GetCapRegs">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will return duty cycle of the input signal." URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_getdutycycle" APIName="CAP001_GetDutyCycle">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will return period of the input signal." URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_getperiod" APIName="CAP001_GetPeriod">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will return duty cycle and period of the input signal" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_getdutyperiod" APIName="CAP001_GetDutyPeriod">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will read timer status - Running or idle." URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_gettimerstatus" APIName="CAP001_GetTimerStatus">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will start this APP which will start the CCU4_Ccy." URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_start" APIName="CAP001_Start">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will stop this APP which will stop the CCU4_CCy " URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_stop" APIName="CAP001_Stop">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will read the capture registers and updae the dynamic handle." URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_readcapturedvalues" APIName="CAP001_ReadCapturedValues">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will enable the event." URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_enableevent" APIName="CAP001_EnableEvent"/>
  <provided xsi:type="ResourceModel:API" description="This function will enable the event." URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_enableevent" APIName="CAP001_EnableEvent">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will disable the event." URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_disableevent" APIName="CAP001_DisableEvent">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will reset the event." URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_clearpendingevent" APIName="CAP001_ClearPendingEvent">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will enable the event." URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_setpendingevent" APIName="CAP001_SetPendingEvent">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:API" description="This function will check whether given event is set." URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_getpendingevent" APIName="CAP001_GetPendingEvent">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_tempdefresolution" isSystemDefined="true">
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_temptimer" upWardMappingList="//@provided.22 //@provided.22/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_tempcapture" upWardMappingList="//@provided.25 //@provided.25/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_tempstart" upWardMappingList="//@provided.24 //@provided.24/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_tempduty" upWardMappingList="//@provided.14 //@provided.14/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_tempresolution" upWardMappingList="//@provided.16 //@provided.17 //@provided.18 //@provided.19" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="14"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="14"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/cap001_tempminfreq" upWardMappingList="//@provided.20 //@provided.21 //@provided.23" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="7d0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="7d0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice">
    <downWardmappedList xsi:type="ResourceModel:ResourceGroup" href="../../CCU43/CCU43_3.dd#//@provided.0"/>
    <requiredResource uriString="peripheral/ccu4/*/cc4/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="function resourceCondition() {&#xD;&#xA;          var Res0 = Solver.getResource(&quot;cap001_erwtimermode/1&quot;);&#xD;&#xA;          var tc = Solver.getIntValue(Res0);&#xD;&#xA;          if (tc == 1) {&#xD;&#xA;            return true; &#xD;&#xA;          } &#xD;&#xA;          return false;&#xD;&#xA;&#xD;&#xA;        }" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice1">
    <requiredResource uriString="peripheral/ccu4/*/cc4/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/ccu4globalapp">
    <downWardmappedList xsi:type="ResourceModel:App" href="../../CCU4GLOBAL/1.0.22/ccu4global_0.app#/"/>
    <requiredResource uriString="app/ccu4global/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice1/gp0_unsync" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice1/concat_bus_out" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/gp1_unsync" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU43/CCU43_3.dd#//@provided.1"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/gp0_unsync" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU43/CCU43_3.dd#//@provided.2"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice1/e1as" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/global_signal" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU43/CCU43_3.dd#//@provided.3"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/ins" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU43/CCU43_3.dd#//@provided.4"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/ins/lpf0m" upWardMappingList="//@provided.12 //@provided.12/@item.0 //@provided.12/@item.1 //@provided.12/@item.2 //@provided.12/@item.3" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU43/CCU43_3.dd#//@provided.4/@bitFields.9"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/ins/lpf1m" upWardMappingList="//@provided.12/@item.0 //@provided.12/@item.1 //@provided.12/@item.2 //@provided.12/@item.3" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU43/CCU43_3.dd#//@provided.4/@bitFields.10"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/ins/ev0em" upWardMappingList="//@provided.13 //@provided.13/@item.0 //@provided.13/@item.1" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU43/CCU43_3.dd#//@provided.4/@bitFields.3"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/ins/ev1em" upWardMappingList="//@provided.13/@item.0 //@provided.13/@item.1" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU43/CCU43_3.dd#//@provided.4/@bitFields.4"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/cmc" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU43/CCU43_3.dd#//@provided.5"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/cmc/tce" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU43/CCU43_3.dd#//@provided.5/@bitFields.11"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/tc" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU43/CCU43_3.dd#//@provided.6"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/tc/fpe" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU43/CCU43_3.dd#//@provided.6/@bitFields.12"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/tc/ccs" upWardMappingList="//@provided.11 //@provided.11/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU43/CCU43_3.dd#//@provided.6/@bitFields.9"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/psl" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU43/CCU43_3.dd#//@provided.7"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/psc" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU43/CCU43_3.dd#//@provided.8"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/psc/psiv" upWardMappingList="//@provided.16 //@provided.17 //@provided.18 //@provided.21 //@provided.23" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CCU43/CCU43_3.dd#//@provided.8/@bitFields.0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/fpc" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU43/CCU43_3.dd#//@provided.9"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/fpcs" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU43/CCU43_3.dd#//@provided.10"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/pr" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU43/CCU43_3.dd#//@provided.11"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/c0v" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU43/CCU43_3.dd#//@provided.12"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/c1v" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU43/CCU43_3.dd#//@provided.13"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/c2v" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU43/CCU43_3.dd#//@provided.14"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/c3v" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
    <downWardmappedList xsi:type="ResourceModel:RegisterParameter" href="../../CCU43/CCU43_3.dd#//@provided.15"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="00000000"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/ccu4globalapp/ccu4global_irclock" upWardMappingList="//@provided.15 //@provided.16 //@provided.17 //@provided.18 //@provided.19 //@provided.20 //@provided.21 //@provided.23" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="-1"/>
    <downWardmappedList xsi:type="ResourceModel:IntegerParameter" href="../../CCU4GLOBAL/1.0.22/ccu4global_0.app#//@provided.2"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="78"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/concat_bus_in" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU43/CCU43_3.dd#//@provided.16"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice1/e0as" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/e1as" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU43/CCU43_3.dd#//@provided.17"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice/e0as" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU43/CCU43_3.dd#//@provided.18"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.24/app/cap001/0/slice1/gp1_unsync" isSystemDefined="true"/>
  <propertyConstants name="uridevice" value="device">
    <propertyConstants name="uriPeri_CCU4" value="peripheral/ccu4/">
      <propertyConstants name="uricap001App" value="app/cap001/"/>
    </propertyConstants>
  </propertyConstants>
  <categoryDescription description="Peripheral related Apps" name="Peripheral Specific Apps">
    <subCategory description="Timer-Capture-Compare" name="Timer-Capture-Compare">
      <subCategory description="CAPCOM4" name="Capture/Compare Unit 4 (CAPCOM4)"/>
    </subCategory>
  </categoryDescription>
  <categoryDescription description="Basic Applications" name="Basic Applications">
    <subCategory description="Apps related to Capture/Compare" name="Time Processing">
      <subCategory description="Signal Capture" name="Signal Capture"/>
    </subCategory>
  </categoryDescription>
  <manifestInfo version="1.0.24">
    <keywords>Capture PWM Duty cycle and period</keywords>
    <keywords>CCU4 external capture mode</keywords>
    <keywords>CAP001</keywords>
    <keywords>Period Measurement</keywords>
    <properties xsi:type="ResourceModel:AppProperties_1_0" initProvider="true"/>
  </manifestInfo>
  <datagenerate fileName="CAP001.h" fileType="HFILE" templateFileName="CAP001.hdt" templateEngine="NONE" fileAction="COPY"/>
  <datagenerate fileName="CAP001_Conf.h" fileType="HFILE" templateFileName="CAP001Confh.jet"/>
  <datagenerate fileName="CAP001.c" templateFileName="CAP001c.jet"/>
  <datagenerate fileName="CAP001_Conf.c" templateFileName="CAP001Confc.jet"/>
  <connections sourceSignal="ccu4globalapp/ccu4global_globalsignal_vs" targetSignal="app/cap001/0/cap001_globalsignal_vs"/>
  <connections sourceSignal="app/cap001/0/cap001_output_concatenation_vs" targetSignal="app/cap001/0/cap001_input_concatenation_vs"/>
  <softwareIdList>45.0.1</softwareIdList>
  <softwareIdList>45.0.2</softwareIdList>
  <softwareIdList>45.0.3</softwareIdList>
  <softwareIdList>45.2.3</softwareIdList>
  <softwareIdList>45.4.2</softwareIdList>
  <softwareIdList>45.4.3</softwareIdList>
  <softwareIdList>45.0200.1</softwareIdList>
  <softwareIdList>45.0200.2</softwareIdList>
  <softwareIdList>45.0200.3</softwareIdList>
  <softwareIdList>45.0202.3</softwareIdList>
  <softwareIdList>45.0204.3</softwareIdList>
  <softwareIdList>45.0204.2</softwareIdList>
  <softwareIdList>44.0.3</softwareIdList>
  <softwareIdList>44.00.5</softwareIdList>
  <softwareIdList>44.02.3</softwareIdList>
  <softwareIdList>44.02.5</softwareIdList>
  <softwareIdList>42.00.5</softwareIdList>
  <softwareIdList>42.0.6</softwareIdList>
  <softwareIdList>42.04.5</softwareIdList>
  <softwareIdList>42.04.6</softwareIdList>
  <softwareIdList>11.0100.7</softwareIdList>
  <softwareIdList>11.0100.9</softwareIdList>
  <softwareIdList>12.0100.7</softwareIdList>
  <softwareIdList>13.0102.7</softwareIdList>
  <softwareIdList>12.0101.7</softwareIdList>
  <softwareIdList>12.0102.9</softwareIdList>
  <softwareIdList>12.0102.8</softwareIdList>
  <softwareIdList>13.0101.9</softwareIdList>
  <softwareIdList>13.0101.7</softwareIdList>
  <softwareIdList>42.0200.5</softwareIdList>
  <softwareIdList>42.0204.5</softwareIdList>
  <softwareIdList>42.0204.6</softwareIdList>
  <softwareIdList>42.0200.6</softwareIdList>
  <softwareIdList>42.0208.6</softwareIdList>
  <softwareIdList>44.0200.5</softwareIdList>
  <softwareIdList>44.0202.3</softwareIdList>
  <softwareIdList>44.0202.5</softwareIdList>
  <softwareIdList>44.0200.3</softwareIdList>
  <softwareIdList>45.0300.1</softwareIdList>
  <softwareIdList>45.0300.3</softwareIdList>
  <softwareIdList>45.0302.3</softwareIdList>
  <softwareIdList>45.0304.2</softwareIdList>
  <softwareIdList>45.0300.2</softwareIdList>
  <softwareIdList>45.0304.3</softwareIdList>
  <softwareIdList>11.0100.10</softwareIdList>
  <softwareIdList>11.0100.11</softwareIdList>
  <softwareIdList>12.0101.11</softwareIdList>
  <softwareIdList>12.0102.10</softwareIdList>
  <softwareIdList>12.0102.11</softwareIdList>
  <softwareIdList>13.0101.10</softwareIdList>
  <softwareIdList>13.0101.11</softwareIdList>
  <softwareIdList>13.0102.10</softwareIdList>
  <softwareIdList>13.0102.11</softwareIdList>
  <softwareIdList>13.0102.9</softwareIdList>
</ResourceModel:App>
