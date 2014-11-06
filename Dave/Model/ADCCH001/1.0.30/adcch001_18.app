<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="ADCCH001" description="This App provides the &#xA; ADC Channel configurations and &#xA; ADC Conversion Result configurations. &#xA; Use this App with Queue(ADC002), &#xA; or Scan(ADC003) Request Source. &#xA; For standalone operation of this &#xA; App, use ADCGLOB001 App. " descriptionURL="/doc/html/group___a_d_c_c_h001_app.html" mode="SHARABLE" URI="http://www.infineon.com/1.0.30/app/adcch001/18">
  <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../ADC002/1.0.26/adc002_3.app#//@consumed.17"/>
  <provided xsi:type="ResourceModel:VirtualSignal" name="ADC Channel" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_ch_vs" requiredSignalResource="adcch/gch">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Channel Select" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_select_vs" requiredSignalResource="adcch/select">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result Select" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_resselect_vs" requiredSignalResource="adcch/res_sel">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Channel Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_chanevent_vs" requiredSignalResource="adcch/cev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result Register" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_res0_vs" requiredSignalResource="result_a/res_sel">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Boundary Flag for Result Register A" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_bfl0_vs" requiredSignalResource="result_a/gbflout">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Boundary Flag for Result Register B" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_bfl1_vs" requiredSignalResource="result_b/gbflout">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Boundary Flag for Result Register C" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_bfl2_vs" requiredSignalResource="result_c/gbflout">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Boundary Flag for Result Register D" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_bfl3_vs" requiredSignalResource="result_d/gbflout">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result A Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_reseventa_vs" requiredSignalResource="result_a/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result B Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_reseventb_vs" requiredSignalResource="result_b/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result C Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_reseventc_vs" requiredSignalResource="result_c/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result D Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_reseventd_vs" requiredSignalResource="result_d/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result E Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_resevente_vs" requiredSignalResource="result_e/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result F Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_reseventf_vs" requiredSignalResource="result_f/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result G Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_reseventg_vs" requiredSignalResource="result_g/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result H Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_reseventh_vs" requiredSignalResource="result_h/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result I Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_reseventi_vs" requiredSignalResource="result_i/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result J Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_reseventj_vs" requiredSignalResource="result_j/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result K Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_reseventk_vs" requiredSignalResource="result_k/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result L Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_reseventl_vs" requiredSignalResource="result_l/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result M Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_reseventm_vs" requiredSignalResource="result_m/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result N Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_reseventn_vs" requiredSignalResource="result_n/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result O Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_resevento_vs" requiredSignalResource="result_o/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Result P Event" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_reseventp_vs" requiredSignalResource="result_p/rev">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Gain Control" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;temp_shs_GainControl&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;temp_shs_GainControl&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_shs_gaincontrol" downWardmappedList="//@consumed.0">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows the user to select the gain for the channel.</toolTipHelpDescription>
    <item name="Gain Factor 1" evalFunction="&#xD;&#xA;                      function ForwardMapping()&#xD;&#xA;                        {&#xD;&#xA;                        var value = SCM.getIntValue(currentResource);&#xD;&#xA;                        var Res = SCM.getResource(&quot;temp_shs_GainControl&quot;);&#xD;&#xA;                        if(value == 1)&#xD;&#xA;                          SCM.setIntValue(Res,0);&#xD;&#xA;                       }&#xD;&#xA;                      function BackwardMapping()&#xD;&#xA;                        {&#xD;&#xA;                           var Res = SCM.getResource(&quot;temp_shs_GainControl&quot;);&#xD;&#xA;                           var value = SCM.getIntValue(Res);&#xD;&#xA;                           if(value == 0)&#xD;&#xA;                            SCM.setIntValue(currentResource,1);&#xD;&#xA;                           else&#xD;&#xA;                            SCM.setIntValue(currentResource,0);&#xD;&#xA;                        }&#xD;&#xA;" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_shs_gaincontrol/0" downWardmappedList="//@consumed.0" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Selected Gain Factor is 1</toolTipHelpDescription>
    </item>
    <item name="Gain Factor 3" evalFunction="&#xD;&#xA;                        function ForwardMapping()&#xD;&#xA;                        {&#xD;&#xA;                        var value = SCM.getIntValue(currentResource);&#xD;&#xA;                        var Res = SCM.getResource(&quot;temp_shs_GainControl&quot;);&#xD;&#xA;                        if(value == 1)&#xD;&#xA;                          SCM.setIntValue(Res,1);&#xD;&#xA;                       }&#xD;&#xA;                        function BackwardMapping()&#xD;&#xA;                        {&#xD;&#xA;                           var Res = SCM.getResource(&quot;temp_shs_GainControl&quot;);&#xD;&#xA;                           var value = SCM.getIntValue(Res);&#xD;&#xA;                           if(value == 1)&#xD;&#xA;                            SCM.setIntValue(currentResource,1);&#xD;&#xA;                           else&#xD;&#xA;                            SCM.setIntValue(currentResource,0);&#xD;&#xA;                          }&#xD;&#xA;" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_shs_gaincontrol/1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Selected Gain Factor is 3</toolTipHelpDescription>
    </item>
    <item name="Gain Factor 6" evalFunction="&#xD;&#xA;                        function ForwardMapping()&#xD;&#xA;                        {&#xD;&#xA;                        var value = SCM.getIntValue(currentResource);&#xD;&#xA;                        var Res = SCM.getResource(&quot;temp_shs_GainControl&quot;);&#xD;&#xA;                        if(value == 1)&#xD;&#xA;                          SCM.setIntValue(Res,2);&#xD;&#xA;                       }&#xD;&#xA;                        function BackwardMapping()&#xD;&#xA;                        {&#xD;&#xA;                           var Res = SCM.getResource(&quot;temp_shs_GainControl&quot;);&#xD;&#xA;                           var value = SCM.getIntValue(Res);&#xD;&#xA;                           if(value == 2)&#xD;&#xA;                            SCM.setIntValue(currentResource,1);&#xD;&#xA;                           else&#xD;&#xA;                            SCM.setIntValue(currentResource,0);&#xD;&#xA;                          }&#xD;&#xA;" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_shs_gaincontrol/2" maxValue="2" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Selected Gain Factor is 6</toolTipHelpDescription>
    </item>
    <item name="Gain Factor 12" evalFunction="&#xD;&#xA;                        function ForwardMapping()&#xD;&#xA;                        {&#xD;&#xA;                        var value = SCM.getIntValue(currentResource);&#xD;&#xA;                        var Res = SCM.getResource(&quot;temp_shs_GainControl&quot;);&#xD;&#xA;                        if(value == 1)&#xD;&#xA;                          SCM.setIntValue(Res,3);&#xD;&#xA;                        }&#xD;&#xA;                        function BackwardMapping()&#xD;&#xA;                        {&#xD;&#xA;                           var Res = SCM.getResource(&quot;temp_shs_GainControl&quot;);&#xD;&#xA;                           var value = SCM.getIntValue(Res);&#xD;&#xA;                           if(value == 3)&#xD;&#xA;                            SCM.setIntValue(currentResource,1);&#xD;&#xA;                           else&#xD;&#xA;                            SCM.setIntValue(currentResource,0);&#xD;&#xA;                        }&#xD;&#xA;" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_shs_gaincontrol/3" maxValue="3" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Selected Gain Factor is 12</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Priority Channel" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchass_assch&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchass_assch&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwprioch" downWardmappedList="//@consumed.52" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <toolTipHelpDescription>This allows a user to mark this channel as a priority channel.&#xD;
A priority channel can not be scanned by the Background source.</toolTipHelpDescription>
    <item name="Enable" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchass_assch&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchass_assch&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwprioch/0" downWardmappedList="//@consumed.52" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Selects consumed channel as a priority channel</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Alias Feature" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempalias&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempalias&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwalias" downWardmappedList="//@consumed.5" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows a user to enable or disable alias feature.</toolTipHelpDescription>
    <item name="Enable" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempalias&quot;);&#xD;&#xA;                            var dep = &quot;DependentApp&quot;;&#xD;&#xA;              var ioapp = SCM.getResource(&quot;adc_pin&quot;);&#xD;&#xA;              SCM.setStringValue(ioapp,dep);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempalias&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwalias/0" downWardmappedList="//@consumed.19 //@consumed.5" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Alias feature when enabled, constrains the channel number&#xD;
to channel 0 or channel 1. The Alias Feature redirects conversion requests for channels CH0 and/or CH1&#xD;
to other channel numbers resulting in converion of the same input channel by two independent events.&#xD;
Please connect to another IO001 App pin signal to mark the alias channel number.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Input Class Select" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/iclsel&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/iclsel&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwinputclass" downWardmappedList="//@consumed.53">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows a user to select the input class from 4 available input classes.&#xD;
Input class defines the Sample Time and Conversion Data Width for standard conversions&#xD;
and for EMUX conversions.</toolTipHelpDescription>
    <item name="Group Specific Class 0 (Queue)" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/iclsel&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/iclsel&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 0 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwinputclass/0" downWardmappedList="//@consumed.53" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Group Specific Class 0.&#xD;
Parameters of this class are configured in the ADC002 App (queue).</toolTipHelpDescription>
    </item>
    <item name="Group Specific Class 1 (Scan)" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/iclsel&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/iclsel&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwinputclass/1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Group Specific Class 1&#xD;
Parameters of this class are configured in the ADC003 App (scan).</toolTipHelpDescription>
    </item>
    <item name="Global Class 0" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/iclsel&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,2);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/iclsel&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 2 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwinputclass/2" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Global class 0&#xD;
Parameters of this class are configured in the ADCGLOB001 App (Global) </toolTipHelpDescription>
    </item>
    <item name="Global Class 1" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/iclsel&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,3);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/iclsel&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 3 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwinputclass/3" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Global Class 1&#xD;
Parameters of this class are configured in the ADCGLOB001 App (Global)</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Reference Input" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/refsel&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/refsel&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwrefinput" downWardmappedList="//@consumed.54">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows a user to select the reference input&#xD;
used for the ADC conversion.</toolTipHelpDescription>
    <item name="VAREF" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/refsel&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/refsel&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 0 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwrefinput/0" downWardmappedList="//@consumed.54" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Standard Reference Input - Varef </toolTipHelpDescription>
    </item>
    <item name="CH0" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/refsel&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/refsel&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwrefinput/1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Alternate Reference Input from Channel 0</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Reference Input 1213" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/refsel&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/refsel&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwrefinput1213" downWardmappedList="//@consumed.54">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows a user to select the reference input&#xD;
used for the ADC conversion.</toolTipHelpDescription>
    <item name="VSSC" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/refsel&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/refsel&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 0 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwrefinput1213/0" downWardmappedList="//@consumed.54" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Standard reference ground input voltage - Vssc </toolTipHelpDescription>
    </item>
    <item name="CH0 " evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/refsel&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/refsel&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwrefinput1213/1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Alternate reference ground input voltage from Channel 0</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="External MUX Control" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempmux&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempmux&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwmuxcontrol" downWardmappedList="//@consumed.6" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows user to enable the external multiplexer&#xD;
control for this channel. External Multiplexer parameters are configured in the&#xD;
ADCGROUP001 App (Group)</toolTipHelpDescription>
    <item name="Enable" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempmux&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempmux&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwmuxcontrol/0" downWardmappedList="//@consumed.6" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Enables the external multiplexer control.&#xD;
External analog multiplexer can be connected to this channel to increase the number&#xD;
of the input analog channels.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Wait for Read Mode" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempwfr&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempwfr&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwwaitforread" downWardmappedList="//@consumed.7">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <toolTipHelpDescription>This allows a user to select the result register write mode.</toolTipHelpDescription>
    <item name="Overwrite" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempwfr&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempwfr&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 0 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwwaitforread/0" downWardmappedList="//@consumed.7" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Result of the conversion is written to register as soon as&#xD;
new result is available.</toolTipHelpDescription>
    </item>
    <item name="Wait For Read" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempwfr&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempwfr&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwwaitforread/1" downWardmappedList="//@consumed.7" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Result of the conversion is written to register only&#xD;
when previous result is read</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Result Position" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_temprespos&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_temprespos&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwresultpos" downWardmappedList="//@consumed.8">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows a user to select the alignment of the result.</toolTipHelpDescription>
    <item name="Left-Aligned" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_temprespos&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_temprespos&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 0 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwresultpos/0" downWardmappedList="//@consumed.8" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Result of the conversion is left aligned 12-bit value.&#xD;
Data width depends upon the conversion mode.&#xD;
For Data Accumulation mode, Data Width = Data Width of conversion mode + 3 bits&#xD;
and Result of the conversion is left aligned 16-bit value.</toolTipHelpDescription>
    </item>
    <item name="Right-Aligned" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_temprespos&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_temprespos&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwresultpos/1" downWardmappedList="//@consumed.8" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Result of the conversion is right-aligned.&#xD;
Data width depends upon the conversion mode.&#xD;
For Data Accumulation mode, Data Width = Data Width of conversion mode + 3 bits</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Data Modification" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf" downWardmappedList="//@consumed.10">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="3"/>
    <toolTipHelpDescription>This gives the option to modify the result data&#xD;
before writing to the result register. These options reduce the CPU/DMA load to process the data.</toolTipHelpDescription>
    <item name="No Data Modification" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 0 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/0" downWardmappedList="//@consumed.10" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>No data modification. Result is directly written to the&#xD;
Result Register.</toolTipHelpDescription>
    </item>
    <item name="Accumulate 2 Results" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>2 conversion results are accumulated to generate&#xD;
final result.</toolTipHelpDescription>
    </item>
    <item name="Accumulate 3 Results" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,2);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 2 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/2" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>3 conversion results are accumulated to generate&#xD;
final result.</toolTipHelpDescription>
    </item>
    <item name="Accumulate 4 Results" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,3);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 3 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/3" downWardmappedList="//@consumed.10" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>4 conversion results are accumulated to generate&#xD;
final result.</toolTipHelpDescription>
    </item>
    <item name="Difference Mode" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,20);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 20 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/4" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>In this mode, Result Register 0 value is subtracted&#xD;
from the Conversion value to get the final result. </toolTipHelpDescription>
    </item>
    <item name="FIR filter: a=2, b=1, c=0" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,4);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 4 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/5" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>FIR filter&#xD;
The conversion result and the intermediate result buffer values&#xD;
are added weighted with their respective coefficients (a, b, c) to form the final value for the result register.</toolTipHelpDescription>
    </item>
    <item name="FIR filter: a=1, b=2, c=0" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,5);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 5 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/6" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>FIR filter&#xD;
The conversion result and the intermediate result buffer values&#xD;
are added weighted with their respective coefficients (a, b, c) to form the final value for the result register.</toolTipHelpDescription>
    </item>
    <item name="FIR filter: a=2, b=0, c=1" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,6);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 6 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/7" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>FIR filter&#xD;
The conversion result and the intermediate result buffer values&#xD;
are added weighted with their respective coefficients (a, b, c) to form the final value for the result register.</toolTipHelpDescription>
    </item>
    <item name="FIR filter: a=1, b=1, c=1" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,7);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 7 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/8" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>FIR filter&#xD;
The conversion result and the intermediate result buffer values&#xD;
are added weighted with their respective coefficients (a, b, c) to form the final value for the result register.</toolTipHelpDescription>
    </item>
    <item name="FIR filter: a=1, b=0, c=2" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,8);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 8 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/9" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>FIR filter&#xD;
The conversion result and the intermediate result buffer values&#xD;
are added weighted with their respective coefficients (a, b, c) to form the final value for the result register.</toolTipHelpDescription>
    </item>
    <item name="FIR filter: a=3, b=1, c=0" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,9);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 9 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/10" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>FIR filter&#xD;
The conversion result and the intermediate result buffer values&#xD;
are added weighted with their respective coefficients (a, b, c) to form the final value for the result register.</toolTipHelpDescription>
    </item>
    <item name="FIR filter: a=2, b=2, c=0" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,10);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 10 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/11" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>FIR filter&#xD;
The conversion result and the intermediate result buffer values&#xD;
are added weighted with their respective coefficients (a, b, c) to form the final value for the result register.</toolTipHelpDescription>
    </item>
    <item name="FIR filter: a=1, b=3, c=0" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,11);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 11 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/12" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>FIR filter&#xD;
The conversion result and the intermediate result buffer values&#xD;
are added weighted with their respective coefficients (a, b, c) to form the final value for the result register.</toolTipHelpDescription>
    </item>
    <item name="FIR filter: a=3, b=0, c=1" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,12);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 12 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/13" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>FIR filter&#xD;
The conversion result and the intermediate result buffer values&#xD;
are added weighted with their respective coefficients (a, b, c) to form the final value for the result register.</toolTipHelpDescription>
    </item>
    <item name="FIR filter: a=2, b=1, c=1" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,13);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 13 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/14" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>FIR filter&#xD;
The conversion result and the intermediate result buffer values&#xD;
are added weighted with their respective coefficients (a, b, c) to form the final value for the result register.</toolTipHelpDescription>
    </item>
    <item name="FIR filter: a=1, b=2, c=1" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,14);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 14 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/15" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>FIR filter&#xD;
The conversion result and the intermediate result buffer values&#xD;
are added weighted with their respective coefficients (a, b, c) to form the final value for the result register.</toolTipHelpDescription>
    </item>
    <item name="FIR filter: a=2, b=0, c=2" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,15);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 15 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/16" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>FIR filter&#xD;
The conversion result and the intermediate result buffer values&#xD;
are added weighted with their respective coefficients (a, b, c) to form the final value for the result register.</toolTipHelpDescription>
    </item>
    <item name="FIR filter: a=1, b=1, c=2" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,16);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 16 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/17" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>FIR filter&#xD;
The conversion result and the intermediate result buffer values&#xD;
are added weighted with their respective coefficients (a, b, c) to form the final value for the result register.</toolTipHelpDescription>
    </item>
    <item name="FIR filter: a=1, b=0, c=3" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,17);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 17 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/18" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>FIR filter&#xD;
The conversion result and the intermediate result buffer values&#xD;
are added weighted with their respective coefficients (a, b, c) to form the final value for the result register.</toolTipHelpDescription>
    </item>
    <item name="IIR filter: a=2, b=2" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,18);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 18 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/19" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>IIR filter&#xD;
The conversion result, weighted with the respective coefficients (a, b), and a fraction of the&#xD;
previous result are added to form the final value for the result register.</toolTipHelpDescription>
    </item>
    <item name="IIR filter: a=3, b=4" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,19);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempdatareduction&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 19 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwdatamodf/20" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>IIR filter&#xD;
The conversion result, weighted with the respective coefficient (a, b), and a fraction of the&#xD;
previous result are added to form the final value for the result register.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Result FIFO" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempfifo&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempfifo&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwfifo" downWardmappedList="//@consumed.12" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows a user to enable the FIFO buffer to store the results.&#xD;
A result FIFO stores several measurement&#xD;
results that can be read out later with a relaxed CPU response timing.&#xD;
Result FIFO is not supported in the Fast Compare Mode.</toolTipHelpDescription>
    <item name="Enable" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempfifo&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempfifo&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwfifo/0" downWardmappedList="//@consumed.12" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>This forms the FIFO result buffer by concatenating two&#xD;
or more consecutive result registers.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Number of FIFO registers" evalFunction="&#xD;&#xA;        function ForwardMapping(){&#xD;&#xA;              var fifo_res = SCM.getResource(&quot;adcch001_tempfifo&quot;);&#xD;&#xA;              var fifo = SCM.getIntValue(fifo_res);&#xD;&#xA;&#xD;&#xA;              var iores = SCM.getResource(&quot;adc_pin/io001_erwinputchar&quot;);&#xD;&#xA;              SCM.setIntValue(iores, 0);&#xD;&#xA;&#xD;&#xA;              var value2 = SCM.getIntValue(currentResource);&#xD;&#xA;              var tempRes = SCM.getResource(&quot;adcch001_tempfifono&quot;);&#xD;&#xA;              SCM.setIntValue(tempRes,value2);&#xD;&#xA;        }&#xD;&#xA;        function BackwardMapping(){&#xD;&#xA;            var fifo_res = SCM.getResource(&quot;adcch001_tempfifo&quot;);&#xD;&#xA;            var fifo = SCM.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 0)&#xD;&#xA;                        {&#xD;&#xA;                            SCM.setIntValue(currentResource,2);&#xD;&#xA;                        }&#xD;&#xA;                        else {&#xD;&#xA;                var tempRes = SCM.getResource(&quot;adcch001_tempfifono&quot;);&#xD;&#xA;                var value = SCM.getIntValue(tempRes);&#xD;&#xA;                SCM.setIntValue(currentResource,value);&#xD;&#xA;                        }&#xD;&#xA;        }&#xD;&#xA;        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_irwfifono" downWardmappedList="//@consumed.59 //@consumed.13" maxValue="10" minValue="2">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="2"/>
    <localValue xsi:type="ResourceModel:StringValue" value="2"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="2"/>
    <toolTipHelpDescription>This is the number of stages in a result FIFO.&#xD;
Conversion results are stored to the register with the highest index of a FIFO structure.&#xD;
App reads the result from the FIFO register with the lowest index.</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Fast Compare Mode" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempfastcompmode&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempfastcompmode&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwcomparator" downWardmappedList="//@consumed.16" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>In Fast Compare mode, input signal is compared against the&#xD;
value in the result register and binary result is generated if input signal is&#xD;
above or below the compare result value.</toolTipHelpDescription>
    <item name="Enable" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempfastcompmode&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempfastcompmode&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwcomparator/0" downWardmappedList="//@consumed.16" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Enable Fast Compare Mode.&#xD;
Please make sure that the selected input class is configured for the 10-bit fast compare mode.&#xD;
If EMUX conversion mode is configured for the 10-bit fast compare mode,&#xD;
Please enable EMUX control for this channel.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Result Compare Value" evalFunction="&#xD;&#xA;        function ForwardMapping(){&#xD;&#xA;              var fifo_res = SCM.getResource(&quot;adcch001_tempfastcompmode&quot;);&#xD;&#xA;              var fifo = SCM.getIntValue(fifo_res);&#xD;&#xA;&#xD;&#xA;              var value2 = SCM.getIntValue(currentResource);&#xD;&#xA;              var tempRes = SCM.getResource(&quot;adcch001_tempcompvalue&quot;);&#xD;&#xA;              SCM.setIntValue(tempRes,value2);&#xD;&#xA;        }&#xD;&#xA;        function BackwardMapping(){&#xD;&#xA;            var fifo_res = SCM.getResource(&quot;adcch001_tempfastcompmode&quot;);&#xD;&#xA;            var comp = SCM.getIntValue(fifo_res);&#xD;&#xA;                        if(comp == 0)&#xD;&#xA;                        {&#xD;&#xA;                            SCM.setIntValue(currentResource,0);&#xD;&#xA;                        }&#xD;&#xA;                        else {&#xD;&#xA;                var tempRes = SCM.getResource(&quot;adcch001_tempcompvalue&quot;);&#xD;&#xA;                var value = SCM.getIntValue(tempRes);&#xD;&#xA;                SCM.setIntValue(currentResource,value);&#xD;&#xA;                        }&#xD;&#xA;        }&#xD;&#xA;        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_irwcompvalue" downWardmappedList="//@consumed.17" maxValue="3FF" minValue="0">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="200"/>
    <localValue xsi:type="ResourceModel:StringValue" value="200"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This is the 10-bit compare value used for the&#xD;
fast comparision. Comparison is done with 10-bit left-aligned value i.e&#xD;
with bits 11-2. Given value is left-shifted by 2 before writing into the Result Register.</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Channel Event Mode" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/chevmode&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/chevmode&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwchevtmode" downWardmappedList="//@consumed.56">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows a user to enable the channel event based on limit checking.&#xD;
To get the Interrupt, Connect Channel Event Signal to NVIC002 App. </toolTipHelpDescription>
    <item name="Never" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/chevmode&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/chevmode&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 0 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwchevtmode/0" downWardmappedList="//@consumed.56" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Channel Event is disabled</toolTipHelpDescription>
    </item>
    <item name="Result is Inside Boundary" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/chevmode&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/chevmode&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwchevtmode/1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Event is generated if result is inside boundary.&#xD;
For Fast Compare Mode, Event is generated if the result is above the Result Compare Value.&#xD;
To get the Interrupt, Connect Channel Event Signal to NVIC002 App. </toolTipHelpDescription>
    </item>
    <item name="Result is Outside Boundary" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/chevmode&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res, 2);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/chevmode&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value == 2 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwchevtmode/2" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Event is generated if result is outside boundary.&#xD;
For Fast Compare Mode, Event is generated if the result is below the Result Compare Value.&#xD;
To get the Interrupt, Connect Channel Event Signal to NVIC002 App. </toolTipHelpDescription>
    </item>
    <item name="Always" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/chevmode&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,3);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/chevmode&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value == 3 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwchevtmode/3" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Event is generated for evry result conversion.&#xD;
To get the Interrupt, Connect Channel Event Signal to NVIC002 App. </toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Upper Boundary Select" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndselu&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndselu&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwubselect" downWardmappedList="//@consumed.57">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <toolTipHelpDescription>The lower and the upper boundary value define the band of the limit check function.&#xD;
The channel event can be triggered if the result is inside or outside the specified band.</toolTipHelpDescription>
    <item name="Group Specific Boundary 0" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndselu&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndselu&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 0 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwubselect/0" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Group Boundary 0.&#xD;
Boundary value is defined in the  ADCGROUP001 App</toolTipHelpDescription>
    </item>
    <item name="Group Specific Boundary 1" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndselu&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndselu&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwubselect/1" downWardmappedList="//@consumed.57" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Group Boundary 1.&#xD;
Boundary value is defined in the  ADCGROUP001 App </toolTipHelpDescription>
    </item>
    <item name="Global Boundary 0" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndselu&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,2);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndselu&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 2 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwubselect/2" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Global Boundary 0.&#xD;
Boundary value is defined in the  ADCGLOB001 App</toolTipHelpDescription>
    </item>
    <item name="Global Boundary 1" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndselu&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,3);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndselu&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 3 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwubselect/3" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Global Boundary 1.&#xD;
Boundary value is defined in the  ADCGLOB001 App</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Lower Boundary Select" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndsell&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndsell&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwlbselect" downWardmappedList="//@consumed.58">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>The lower and the upper boundary value define the band of the limit check function.&#xD;
The channel event can be triggered if the result is inside or outside the specified band.</toolTipHelpDescription>
    <item name="Group Specific Boundary 0" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndsell&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndsell&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 0 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwlbselect/0" downWardmappedList="//@consumed.58" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Group Boundary 0.&#xD;
Boundary value is defined in the  ADCGROUP001 App</toolTipHelpDescription>
    </item>
    <item name="Group Specific Boundary 1" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndsell&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndsell&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwlbselect/1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Group Boundary 1.&#xD;
Boundary value is defined in the  ADCGROUP001 App</toolTipHelpDescription>
    </item>
    <item name="Global Boundary 0" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndsell&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,2);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndsell&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 2 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwlbselect/2" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Global Boundary 0.&#xD;
Boundary value is defined in the  ADCGLOB001 App</toolTipHelpDescription>
    </item>
    <item name="Global Boundary 1" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndsell&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,3);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/bndsell&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 3 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwlbselect/3" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
      <toolTipHelpDescription>Global Boundary 1.&#xD;
Boundary value is defined in the  ADCGLOB001 App</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Boundary Flag" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundflag&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundflag&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwenableboundaryflag" downWardmappedList="//@consumed.14" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows a user to enable boundary flag.&#xD;
The flag can be set or cleared when the defined level is exceeded.</toolTipHelpDescription>
    <item name="Enable" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundflag&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundflag&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwenableboundaryflag/0" downWardmappedList="//@consumed.14" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>For Standard Conversion Mode, a boundary flag will be set&#xD;
when the conversion result is above the upper boundary,&#xD;
and will be cleared when the conversion result is below the lower boundary.&#xD;
For Fast Compare Mode, boundary flag will be set when&#xD;
the compared signal level is above the compare value,&#xD;
and will be cleared when the signal level is below the compare value.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Boundary Flag Activation" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflgact&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflgact&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwboundaryact" downWardmappedList="//@consumed.3">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows a user to select the Boundary flag activation.</toolTipHelpDescription>
    <item name="Set Boundary Flag if Result is Above the Defined Band, Clear if Below" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflgact&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflgact&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 0 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwboundaryact/0" downWardmappedList="//@consumed.3" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Set boundary flag BFLy (where y = 0 to 3) if result is above the&#xD;
defined band or compare value, clear if below.</toolTipHelpDescription>
    </item>
    <item name="Set Boundary Flag if Result is Below the Defined Band, Clear if Above" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflgact&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflgact&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwboundaryact/1" downWardmappedList="//@consumed.3" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Set boundary flag BFLy (where y = 0 to 3) if result is below the&#xD;
defined band or compare value, clear if above</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Boundary Flag Inversion Control" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflginv&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflginv&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwboundaryinv" downWardmappedList="//@consumed.2">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows a user to select the Boundary Flag Inversion.</toolTipHelpDescription>
    <item name="Use BFL directly." evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflginv&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflginv&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 0 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwboundaryinv/0" downWardmappedList="//@consumed.2" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <toolTipHelpDescription>Use BFLy directly  (where y = 0 to 3).</toolTipHelpDescription>
    </item>
    <item name="Invert BFL Value" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflginv&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflginv&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwboundaryinv/1" downWardmappedList="//@consumed.2" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Invert value and use BFLy (where y = 0 to 3).</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Boundary Flag Mode" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflgmode&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflgmode&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwboundarymode" downWardmappedList="//@consumed.1">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows a user to select the Boundary Flag y (where y = 0 to 3) Mode.</toolTipHelpDescription>
    <item name="Always enable boundary flag." evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflgmode&quot;);&#xD;&#xA;              if (value == 1 )&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflgmode&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 0 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwboundarymode/0" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="1"/>
      <localValue xsi:type="ResourceModel:StringValue" value="1"/>
      <globalValue xsi:type="ResourceModel:StringValue" value="1"/>
      <toolTipHelpDescription>Always enable boundary flag.</toolTipHelpDescription>
    </item>
    <item name="Enable Boundary Flag While Gate of Queue Source is Active" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflgmode&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflgmode&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwboundarymode/1" downWardmappedList="//@consumed.1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Enable boundary flag while gate of queue source is&#xD;
active, clear BFLy (where y = 0 to 3) while gate is inactive.
 This option can be used only for ADC002 app which is a Queue source app.</toolTipHelpDescription>
    </item>
    <item name="Enable Boundary Flag While Gate of Scan Source Active" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflgmode&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,2);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempboundaryflgmode&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 2 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwboundarymode/2" downWardmappedList="//@consumed.1" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Enable boundary flag while gate of Scan source is&#xD;
active, clear BFLy (where y = 0 to 3) while gate is inactive.
 This option can be used only for ADC003 app which is a Scan source app.</toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Result Event" evalFunction="&#xD;&#xA;            function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempresevt&quot;);&#xD;&#xA;              SCM.setIntValue(Res,value);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempresevt&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;          SCM.setIntValue(currentResource,value);&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwenableresevt" downWardmappedList="//@consumed.15" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This allows a user to enable the result event.&#xD;
This event is not available in the fast compare mode.</toolTipHelpDescription>
    <item name="Enable at Initialization" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var value = SCM.getIntValue(currentResource);&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempresevt&quot;);&#xD;&#xA;              if (value == 1 ) {&#xD;&#xA;                SCM.setIntValue(Res,1);&#xD;&#xA;              } else if (value === 0) {&#xD;&#xA;                SCM.setIntValue(Res,0);&#xD;&#xA;              }&#xD;&#xA;&#xD;&#xA;              var comp_res = SCM.getResource(&quot;adcch001_tempfastcompmode&quot;);&#xD;&#xA;              var comp = SCM.getIntValue(comp_res);&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch001_tempresevt&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              var comp_res = SCM.getResource(&quot;adcch001_tempfastcompmode&quot;);&#xD;&#xA;              var comp = SCM.getIntValue(comp_res);&#xD;&#xA;                            if(comp == 1)&#xD;&#xA;                            {&#xD;&#xA;                  SCM.setIntValue(currentResource,0);&#xD;&#xA;                            }&#xD;&#xA;                            else if (value === 1 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwenableresevt/0" downWardmappedList="//@consumed.15" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Enable the result event.&#xD;
Result event is generated when new valid result is available in the result register.&#xD;
To get the Interrupt, Connect corresponding Result Resgitser Event Signal to NVIC002 App. </toolTipHelpDescription>
    </item>
  </provided>
  <provided xsi:type="ResourceModel:EnumerationParameter" name="Channel Event" evalFunction="          " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwenablechannelevt" multipleSelections="true">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="0"/>
    <toolTipHelpDescription>This disaplys the channel event configuration.&#xD;
It will be set as per channel event mode configuration.&#xD;
Channel event indicate that the conversion is finished.</toolTipHelpDescription>
    <item name="Enable at Initialization" evalFunction="function ForwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var mode_res = SCM.getResource(&quot;adcch/gchctr/chevmode&quot;);&#xD;&#xA;              var mode = SCM.getIntValue(mode_res);&#xD;&#xA;&#xD;&#xA;            }&#xD;&#xA;            function BackwardMapping()&#xD;&#xA;            {&#xD;&#xA;              var Res = SCM.getResource(&quot;adcch/gchctr/chevmode&quot;);&#xD;&#xA;              var value = SCM.getIntValue(Res);&#xD;&#xA;              if (value === 0 ) {&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              } else if (value == -1 ){&#xD;&#xA;                SCM.setIntValue(currentResource,0);&#xD;&#xA;              }&#xD;&#xA;              else {&#xD;&#xA;                SCM.setIntValue(currentResource,1);&#xD;&#xA;              }&#xD;&#xA;            }        " URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_erwenablechannelevt/0" maxValue="1" minValue="0">
      <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <localValue xsi:type="ResourceModel:StringValue" value="0"/>
      <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
      <toolTipHelpDescription>Enable the Channel Event</toolTipHelpDescription>
    </item>
  </provided>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/temp_shs_gaincontrol" upWardMappingList="//@provided.25 //@provided.25/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempboundaryflgmode" upWardMappingList="//@provided.45 //@provided.45/@item.1 //@provided.45/@item.2" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempboundaryflginv" upWardMappingList="//@provided.44 //@provided.44/@item.0 //@provided.44/@item.1" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempboundaryflgact" upWardMappingList="//@provided.43 //@provided.43/@item.0 //@provided.43/@item.1" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempchevt" isSystemDefined="true">
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempalias" upWardMappingList="//@provided.27 //@provided.27/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempmux" upWardMappingList="//@provided.31 //@provided.31/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempwfr" upWardMappingList="//@provided.32 //@provided.32/@item.0 //@provided.32/@item.1" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_temprespos" upWardMappingList="//@provided.33 //@provided.33/@item.0 //@provided.33/@item.1" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempdatamodif" isSystemDefined="true">
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempdatareduction" upWardMappingList="//@provided.34 //@provided.34/@item.0 //@provided.34/@item.3" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="3"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="3"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempdatafilter" isSystemDefined="true">
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempfifo" upWardMappingList="//@provided.35 //@provided.35/@item.0 //@provided.36" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempfifono" upWardMappingList="//@provided.36" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="2"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="2"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempboundflag" upWardMappingList="//@provided.42 //@provided.42/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempresevt" upWardMappingList="//@provided.46 //@provided.46/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempfastcompmode" upWardMappingList="//@provided.37 //@provided.37/@item.0 //@provided.38 //@provided.46/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch001_tempcompvalue" upWardMappingList="//@provided.38" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="200"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="200"/>
    <requiredResource uriString="" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var Res0 = Solver.getResource(&quot;adcch001_erwalias/0&quot;);&#xD;&#xA;            var alias = Solver.getIntValue(Res0);&#xD;&#xA;            if (alias == 1) {&#xD;&#xA;              var constr = &quot;reserved([peripheral,vadc,0,group,_,ch,Ch_no],app_alias_ch) \n uri_element_range(Ch_no,[0,1])&quot;;&#xD;&#xA;              Solver.setConstraintString(constr);&#xD;&#xA;            }&#xD;&#xA;&#xD;&#xA;            var value_45 = Solver.getSoftwareId().substring(0,2).compareTo(&quot;45&quot;);&#xD;&#xA;            if(value_45 == 0)&#xD;&#xA;            {&#xD;&#xA;                var boundary_ch = Solver.getResource(&quot;adcch001_erwenableboundaryflag/0&quot;);&#xD;&#xA;                var boundary = Solver.getIntValue(boundary_ch);&#xD;&#xA;&#xD;&#xA;                 if (boundary == 1)  {&#xD;&#xA;                  var constr = &quot;reserved([peripheral,vadc,0,group,_,ch,Ch_no1],app_boundary_ch) \n uri_element_range(Ch_no1,[0,1,2,3])&quot;;&#xD;&#xA;                  Solver.setConstraintString(constr);&#xD;&#xA;                  }&#xD;&#xA;            }&#xD;&#xA;&#xD;&#xA;            return true;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch">
    <downWardmappedList xsi:type="ResourceModel:ResourceGroup" href="../../VADC/VADC_0.dd#//@provided.236"/>
    <requiredResource uriString="peripheral/vadc/0/group/*/ch/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var alias_res = Solver.getResource(&quot;adcch001_erwalias/0&quot;);&#xD;&#xA;            var alias = Solver.getIntValue(alias_res);&#xD;&#xA;&#xD;&#xA;                        if(alias == 0)&#xD;&#xA;                        {&#xD;&#xA;                  return true;&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adc_pin" upWardMappingList="//@provided.27/@item.0">
    <localValue xsi:type="ResourceModel:StringValue" value="DependentApp"/>
    <downWardmappedList xsi:type="ResourceModel:App" href="../../IO001/1.0.16/io001_18.app#/"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="DependentApp"/>
    <requiredResource uriString="app/io001/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var filter_res1 = Solver.getResource(&quot;adcch001_erwdatamodf/5&quot;);&#xD;&#xA;            var filter1 = Solver.getIntValue(filter_res1);&#xD;&#xA;            var filter_res2 = Solver.getResource(&quot;adcch001_erwdatamodf/6&quot;);&#xD;&#xA;            var filter2 = Solver.getIntValue(filter_res2);&#xD;&#xA;            var filter_res3 = Solver.getResource(&quot;adcch001_erwdatamodf/7&quot;);&#xD;&#xA;            var filter3 = Solver.getIntValue(filter_res3);&#xD;&#xA;            var filter_res4 = Solver.getResource(&quot;adcch001_erwdatamodf/8&quot;);&#xD;&#xA;            var filter4 = Solver.getIntValue(filter_res4);&#xD;&#xA;            var filter_res5 = Solver.getResource(&quot;adcch001_erwdatamodf/9&quot;);&#xD;&#xA;            var filter5 = Solver.getIntValue(filter_res5);&#xD;&#xA;            var filter_res6 = Solver.getResource(&quot;adcch001_erwdatamodf/10&quot;);&#xD;&#xA;            var filter6 = Solver.getIntValue(filter_res6);&#xD;&#xA;            var filter_res7 = Solver.getResource(&quot;adcch001_erwdatamodf/11&quot;);&#xD;&#xA;            var filter7 = Solver.getIntValue(filter_res7);&#xD;&#xA;            var filter_res8 = Solver.getResource(&quot;adcch001_erwdatamodf/12&quot;);&#xD;&#xA;            var filter8 = Solver.getIntValue(filter_res8);&#xD;&#xA;            var filter_res9 = Solver.getResource(&quot;adcch001_erwdatamodf/13&quot;);&#xD;&#xA;            var filter9 = Solver.getIntValue(filter_res9);&#xD;&#xA;            var filter_res10 = Solver.getResource(&quot;adcch001_erwdatamodf/14&quot;);&#xD;&#xA;            var filter10 = Solver.getIntValue(filter_res10);&#xD;&#xA;            var filter_res11 = Solver.getResource(&quot;adcch001_erwdatamodf/15&quot;);&#xD;&#xA;            var filter11 = Solver.getIntValue(filter_res11);&#xD;&#xA;            var filter_res12 = Solver.getResource(&quot;adcch001_erwdatamodf/16&quot;);&#xD;&#xA;            var filter12 = Solver.getIntValue(filter_res12);&#xD;&#xA;            var filter_res13 = Solver.getResource(&quot;adcch001_erwdatamodf/17&quot;);&#xD;&#xA;            var filter13 = Solver.getIntValue(filter_res13);&#xD;&#xA;            var filter_res14 = Solver.getResource(&quot;adcch001_erwdatamodf/18&quot;);&#xD;&#xA;            var filter14 = Solver.getIntValue(filter_res14);&#xD;&#xA;            var filter_res15 = Solver.getResource(&quot;adcch001_erwdatamodf/19&quot;);&#xD;&#xA;            var filter15 = Solver.getIntValue(filter_res15);&#xD;&#xA;            var filter_res16 = Solver.getResource(&quot;adcch001_erwdatamodf/20&quot;);&#xD;&#xA;            var filter16 = Solver.getIntValue(filter_res16);&#xD;&#xA;&#xD;&#xA;            var diff_res = Solver.getResource(&quot;adcch001_erwdatamodf/4&quot;);&#xD;&#xA;            var differencemode = Solver.getIntValue(diff_res);&#xD;&#xA;            var boundary_res = Solver.getResource(&quot;adcch001_erwenableboundaryflag/0&quot;);&#xD;&#xA;            var boundary = Solver.getIntValue(boundary_res);&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;&#xD;&#xA;        if ((filter1 == 1) || (filter2 == 1) || (filter3 == 1) || (filter4 == 1)&#xD;&#xA;         || (filter5 == 1) || (filter6 == 1) || (filter7 == 1) || (filter8 == 1) || (filter9 == 1) || (filter10 == 1)&#xD;&#xA;         || (filter11 == 1) || (filter12 == 1) || (filter13 == 1) || (filter14 == 1) || (filter15 == 1) || (filter16 == 1)) {&#xD;&#xA;              var constr = &quot;reserved([peripheral,vadc,0,group,Group0,ResultUri,Res0],app_res0) \n uri_element_range(ResultUri,[result_filter])&quot;;&#xD;&#xA;              Solver.setConstraintString(constr);&#xD;&#xA;            }&#xD;&#xA;            else if ((boundary == 1) &amp;&amp; (differencemode == 1)) {&#xD;&#xA;              var constr = &quot;reserved([peripheral,vadc,0,group,Group0,ResultUri,Res0],app_res0) \n uri_element_range(ResultUri,[result_adv]) \n uri_element_range(Res0,[1,2,3])&quot;;&#xD;&#xA;              Solver.setConstraintString(constr);&#xD;&#xA;            }&#xD;&#xA;            else if ((boundary == 1) &amp;&amp; (differencemode == 0)) {&#xD;&#xA;              var constr = &quot;reserved([peripheral,vadc,0,group,Group0,ResultUri,Res0],app_res0) \n uri_element_range(ResultUri,[result_adv])&quot;;&#xD;&#xA;              Solver.setConstraintString(constr);&#xD;&#xA;            }&#xD;&#xA;            return true;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_a" constraintFunction="reserved([peripheral,vadc,0,group,Group0,_,Res0],app_res0)">
    <downWardmappedList xsi:type="ResourceModel:ResourceGroup" href="../../VADC/VADC_0.dd#//@provided.237"/>
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;&#xD;&#xA;            var fifo_res = Solver.getResource(&quot;adcch001_erwfifo/0&quot;);&#xD;&#xA;            var fifo = Solver.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 1)&#xD;&#xA;                        {&#xD;&#xA;                if ((fifono > 1)) {&#xD;&#xA;                  return true;&#xD;&#xA;                }&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_b" constraintFunction="reserved([peripheral,vadc,0,group,Group1,ResultUri1,Res1],app_res1)&#xD;&#xA;                    uri_element_range(ResultUri1,[result,result_filter, result_adv])&#xD;&#xA;                    linear_constraint(Res1,Res0,-1)&#xD;&#xA;                    linear_constraint(Group1,Group0,0)">
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;            var fifo_res = Solver.getResource(&quot;adcch001_erwfifo/0&quot;);&#xD;&#xA;            var fifo = Solver.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 1)&#xD;&#xA;                        {&#xD;&#xA;                if ((fifono > 2)) {&#xD;&#xA;                  return true;&#xD;&#xA;                }&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_c" constraintFunction="reserved([peripheral,vadc,0,group,Group2,ResultUri2,Res2],app_res2)&#xD;&#xA;                           uri_element_range(ResultUri2,[result,result_filter,result_adv])&#xD;&#xA;                           linear_constraint(Res2,Res1,-1)&#xD;&#xA;                           linear_constraint(Group2,Group1,0)">
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;&#xD;&#xA;            var fifo_res = Solver.getResource(&quot;adcch001_erwfifo/0&quot;);&#xD;&#xA;            var fifo = Solver.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 1)&#xD;&#xA;                        {&#xD;&#xA;                if ((fifono > 3)) {&#xD;&#xA;                  return true;&#xD;&#xA;                }&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_d" constraintFunction="reserved([peripheral,vadc,0,group,Group3,ResultUri3,Res3],app_res3)&#xD;&#xA;                           uri_element_range(ResultUri3,[result,result_filter, result_adv])&#xD;&#xA;                           linear_constraint(Res3,Res2,-1)&#xD;&#xA;                           linear_constraint(Group3,Group2,0)">
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;&#xD;&#xA;            var fifo_res = Solver.getResource(&quot;adcch001_erwfifo/0&quot;);&#xD;&#xA;            var fifo = Solver.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 1)&#xD;&#xA;                        {&#xD;&#xA;                if ((fifono > 4)) {&#xD;&#xA;                  return true;&#xD;&#xA;                }&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_e" constraintFunction="reserved([peripheral,vadc,0,group,Group4,ResultUri4,Res4],app_res4)&#xD;&#xA;                           uri_element_range(ResultUri4,[result,result_filter, result_adv])&#xD;&#xA;                           linear_constraint(Res4,Res3,-1)&#xD;&#xA;                           linear_constraint(Group4,Group3,0)">
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;&#xD;&#xA;            var fifo_res = Solver.getResource(&quot;adcch001_erwfifo/0&quot;);&#xD;&#xA;            var fifo = Solver.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 1)&#xD;&#xA;                        {&#xD;&#xA;                if ((fifono > 5)) {&#xD;&#xA;                  return true;&#xD;&#xA;                }&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_f" constraintFunction="reserved([peripheral,vadc,0,group,Group5,ResultUri5,Res5],app_res5)&#xD;&#xA;                           uri_element_range(ResultUri5,[result,result_filter, result_adv])&#xD;&#xA;                           linear_constraint(Res5,Res4,-1)&#xD;&#xA;                           linear_constraint(Group5,Group4,0)">
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;&#xD;&#xA;            var fifo_res = Solver.getResource(&quot;adcch001_erwfifo/0&quot;);&#xD;&#xA;            var fifo = Solver.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 1)&#xD;&#xA;                        {&#xD;&#xA;                if ((fifono > 6)) {&#xD;&#xA;                  return true;&#xD;&#xA;                }&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_g" constraintFunction="reserved([peripheral,vadc,0,group,Group6,ResultUri6,Res6],app_res6)&#xD;&#xA;                           uri_element_range(ResultUri6,[result,result_filter, result_adv])&#xD;&#xA;                           linear_constraint(Res6,Res5,-1)&#xD;&#xA;                           linear_constraint(Group6,Group5,0)">
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;&#xD;&#xA;            var fifo_res = Solver.getResource(&quot;adcch001_erwfifo/0&quot;);&#xD;&#xA;            var fifo = Solver.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 1)&#xD;&#xA;                        {&#xD;&#xA;                if ((fifono > 7)) {&#xD;&#xA;                  return true;&#xD;&#xA;                }&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_h" constraintFunction="reserved([peripheral,vadc,0,group,Group7,ResultUri7,Res7],app_res7)&#xD;&#xA;                           uri_element_range(ResultUri7,[result,result_filter, result_adv])&#xD;&#xA;                           linear_constraint(Res7,Res6,-1)&#xD;&#xA;                           linear_constraint(Group7,Group6,0)">
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;&#xD;&#xA;            var fifo_res = Solver.getResource(&quot;adcch001_erwfifo/0&quot;);&#xD;&#xA;            var fifo = Solver.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 1)&#xD;&#xA;                        {&#xD;&#xA;                if ((fifono > 8)) {&#xD;&#xA;                  return true;&#xD;&#xA;                }&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_i" constraintFunction="reserved([peripheral,vadc,0,group,Group8,ResultUri8,Res8],app_res8)&#xD;&#xA;                           uri_element_range(ResultUri8,[result,result_filter, result_adv])&#xD;&#xA;                           linear_constraint(Res8,Res7,-1)&#xD;&#xA;                           linear_constraint(Group8,Group7,0)">
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;&#xD;&#xA;            var fifo_res = Solver.getResource(&quot;adcch001_erwfifo/0&quot;);&#xD;&#xA;            var fifo = Solver.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 1)&#xD;&#xA;                        {&#xD;&#xA;                if ((fifono > 9)) {&#xD;&#xA;                  return true;&#xD;&#xA;                }&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_j" constraintFunction="reserved([peripheral,vadc,0,group,Group9,ResultUri9,Res9],app_res9)&#xD;&#xA;                           uri_element_range(ResultUri9,[result,result_filter, result_adv])&#xD;&#xA;                           linear_constraint(Res9,Res8,-1)&#xD;&#xA;                           linear_constraint(Group9,Group8,0)">
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;&#xD;&#xA;            var fifo_res = Solver.getResource(&quot;adcch001_erwfifo/0&quot;);&#xD;&#xA;            var fifo = Solver.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 1)&#xD;&#xA;                        {&#xD;&#xA;                if ((fifono > 10)) {&#xD;&#xA;                  return true;&#xD;&#xA;                }&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_k" constraintFunction="reserved([peripheral,vadc,0,group,Group10,ResultUri10,Res10],app_res10)&#xD;&#xA;                           uri_element_range(ResultUri10,[result,result_filter, result_adv])&#xD;&#xA;                           linear_constraint(Res10,Res9,-1)&#xD;&#xA;                           linear_constraint(Group10,Group9,0)">
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;&#xD;&#xA;            var fifo_res = Solver.getResource(&quot;adcch001_erwfifo/0&quot;);&#xD;&#xA;            var fifo = Solver.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 1)&#xD;&#xA;                        {&#xD;&#xA;                if ((fifono > 11)) {&#xD;&#xA;                  return true;&#xD;&#xA;                }&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_l" constraintFunction="reserved([peripheral,vadc,0,group,Group11,ResultUri11,Res11],app_res11)&#xD;&#xA;                           uri_element_range(ResultUri11,[result,result_filter, result_adv])&#xD;&#xA;                           linear_constraint(Res11,Res10,-1)&#xD;&#xA;                           linear_constraint(Group11,Group10,0)">
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;&#xD;&#xA;            var fifo_res = Solver.getResource(&quot;adcch001_erwfifo/0&quot;);&#xD;&#xA;            var fifo = Solver.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 1)&#xD;&#xA;                        {&#xD;&#xA;                if ((fifono > 12)) {&#xD;&#xA;                  return true;&#xD;&#xA;                }&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_m" constraintFunction="reserved([peripheral,vadc,0,group,Group12,ResultUri12,Res12],app_res12)&#xD;&#xA;                           uri_element_range(ResultUri12,[result,result_filter, result_adv])&#xD;&#xA;                           linear_constraint(Res12,Res11,-1)&#xD;&#xA;                           linear_constraint(Group12,Group11,0)">
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;&#xD;&#xA;            var fifo_res = Solver.getResource(&quot;adcch001_erwfifo/0&quot;);&#xD;&#xA;            var fifo = Solver.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 1)&#xD;&#xA;                        {&#xD;&#xA;                if ((fifono > 13)) {&#xD;&#xA;                  return true;&#xD;&#xA;                }&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_n" constraintFunction="reserved([peripheral,vadc,0,group,Group13,ResultUri13,Res13],app_res13)&#xD;&#xA;                           uri_element_range(ResultUri13,[result,result_filter, result_adv])&#xD;&#xA;                           linear_constraint(Res13,Res12,-1)&#xD;&#xA;                           linear_constraint(Group13,Group12,0)">
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;&#xD;&#xA;            var fifo_res = Solver.getResource(&quot;adcch001_erwfifo/0&quot;);&#xD;&#xA;            var fifo = Solver.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 1)&#xD;&#xA;                        {&#xD;&#xA;                if ((fifono > 14)) {&#xD;&#xA;                  return true;&#xD;&#xA;                }&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_o" constraintFunction="reserved([peripheral,vadc,0,group,Group14,ResultUri14,Res14],app_res14)&#xD;&#xA;                           uri_element_range(ResultUri14,[result,result_filter, result_adv])&#xD;&#xA;                           linear_constraint(Res14,Res13,-1)&#xD;&#xA;                           linear_constraint(Group14,Group13,0)">
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="&#xD;&#xA;          function resourceCondition() {&#xD;&#xA;            var fifono_res = Solver.getResource(&quot;adcch001_irwfifono&quot;);&#xD;&#xA;            var fifono = Solver.getIntValue(fifono_res);&#xD;&#xA;&#xD;&#xA;            var fifo_res = Solver.getResource(&quot;adcch001_erwfifo/0&quot;);&#xD;&#xA;            var fifo = Solver.getIntValue(fifo_res);&#xD;&#xA;                        if(fifo == 1)&#xD;&#xA;                        {&#xD;&#xA;                if ((fifono > 15)) {&#xD;&#xA;                  return true;&#xD;&#xA;                }&#xD;&#xA;                        }&#xD;&#xA;            return false;&#xD;&#xA;          }" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_p" constraintFunction="reserved([peripheral,vadc,0,group,Group15,ResultUri15,Res15],app_res15)&#xD;&#xA;                           uri_element_range(ResultUri15,[result,result_filter, result_adv])&#xD;&#xA;                           linear_constraint(Res15,Res14,-1)&#xD;&#xA;                           linear_constraint(Group15,Group14,0)">
    <requiredResource uriString="peripheral/vadc/0/group/*/result/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_i/rev" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_k/rev" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_m/rev" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_c/gbflout" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_b/gbflout" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch/select" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#/1/@provided.270"/>
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#//@provided.245"/>
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#//@provided.278"/>
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#//@provided.225"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_l/rev" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_a/rev" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#/1/@provided.281"/>
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#//@provided.238"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_d/rev" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch/res_sel" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#/1/@provided.271"/>
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#//@provided.246"/>
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#//@provided.279"/>
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#//@provided.226"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_p/rev" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch/cev" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#/1/@provided.272"/>
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#//@provided.247"/>
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#//@provided.280"/>
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#//@provided.227"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_g/rev" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_c/rev" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_e/rev" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_h/rev" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch/gchass_assch" upWardMappingList="//@provided.26 //@provided.26/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#/1/@provided.273"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.248"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.281"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.228"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch/gchctr/iclsel" upWardMappingList="//@provided.28 //@provided.28/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#/1/@provided.274"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.249"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.282"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.229"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch/gchctr/refsel" upWardMappingList="//@provided.29 //@provided.29/@item.0 //@provided.30 //@provided.30/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#/1/@provided.275"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.250"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.283"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.230"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch/gchctr/sync" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#/1/@provided.276"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.251"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.284"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.231"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch/gchctr/chevmode" upWardMappingList="//@provided.39 //@provided.39/@item.0 //@provided.47/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#/1/@provided.277"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.252"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.285"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.232"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch/gchctr/bndselu" upWardMappingList="//@provided.40 //@provided.40/@item.1" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#/1/@provided.278"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.253"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.286"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.233"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch/gchctr/bndsell" upWardMappingList="//@provided.41 //@provided.41/@item.0" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#/1/@provided.279"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.254"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.287"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../VADC/VADC_0.dd#//@provided.234"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adc_pin/io001_erwinputchar" upWardMappingList="//@provided.36" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <downWardmappedList xsi:type="ResourceModel:EnumerationParameter" href="../../IO001/1.0.16/io001_18.app#//@provided.2"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_a/res_sel" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#/1/@provided.282"/>
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#//@provided.239"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_b/rev" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_o/rev" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_f/rev" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_j/rev" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_d/gbflout" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_n/rev" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/result_a/gbflout" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#/1/@provided.283"/>
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#//@provided.240"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.30/app/adcch001/18/adcch/gch" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#/1/@provided.280"/>
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#//@provided.255"/>
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#//@provided.288"/>
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../VADC/VADC_0.dd#//@provided.235"/>
  </consumed>
  <propertyConstants name="uriprefix_Name" value="http://www.infineon.com/peripheral/vX.Y/XX_PeripheralName/0"/>
  <categoryDescription description="Peripheral Specific Apps" name="Peripheral Specific Apps">
    <subCategory description="Analog" name="Analog">
      <subCategory description="Analog to Digital Converter" name="Versatile Analog to Digital Converter(VADC)"/>
    </subCategory>
  </categoryDescription>
  <categoryDescription description="Basic Applications" name="Basic Applications">
    <subCategory description="Acquisition of Analog Signals" name="Acquisition of Analog Signals"/>
  </categoryDescription>
  <manifestInfo version="1.0.30">
    <keywords>ADC Channel</keywords>
    <keywords>Conversion Result</keywords>
    <keywords>Alias</keywords>
    <keywords>Result Data Handling</keywords>
    <keywords>VADC</keywords>
    <keywords>ADC</keywords>
    <properties xsi:type="ResourceModel:AppProperties_1_0" initProvider="true"/>
  </manifestInfo>
  <datagenerate fileName="ADCCH001.h" fileType="HFILE" templateFileName="ADCCH001h.jet"/>
  <datagenerate fileName="ADCCH001_Conf.h" fileType="HFILE" templateFileName="ADCCH001_Confh.jet"/>
  <datagenerate fileName="ADCCH001_Conf.c" templateFileName="ADCCH001_Confc.jet"/>
  <datagenerate fileName="ADCCH001.c" templateFileName="ADCCH001c.jet"/>
  <connections sourceSignal="app/adcch001/18/adc_pin/io001_vs" targetSignal="app/adcch001/18/adcch001_ch_vs"/>
  <connections sourceSignal="app/adcch001/18/adcch001_resselect_vs" targetSignal="app/adcch001/18/adcch001_res0_vs"/>
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
  <softwareIdList>12.0101.11</softwareIdList>
  <softwareIdList>12.0102.10</softwareIdList>
  <softwareIdList>12.0102.11</softwareIdList>
  <softwareIdList>13.0101.10</softwareIdList>
  <softwareIdList>13.0101.11</softwareIdList>
  <softwareIdList>13.0102.10</softwareIdList>
  <softwareIdList>13.0102.11</softwareIdList>
  <softwareIdList>13.0102.9</softwareIdList>
</ResourceModel:App>
