<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="CCU8GLOBAL" description="This is the global app &#xA; with which CCU8 &#xA; slices of the same module &#xA; are configured. " descriptionURL="/doc/html/group___c_c_u8_g_l_o_b_a_l.html" mode="SHARABLE" URI="http://www.infineon.com/1.0.18/app/ccu8global/1">
  <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../PWMSP002/1.0.32/pwmsp002_4.app#//@consumed.27"/>
  <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../PWMSP002/1.0.32/pwmsp002_5.app#//@consumed.27"/>
  <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../PWMSP002/1.0.32/pwmsp002_6.app#//@consumed.27"/>
  <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../PWMSP002/1.0.32/pwmsp002_7.app#//@consumed.27"/>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Clock" evalFunction="" URI="http://www.infineon.com/1.0.18/app/ccu8global/1/ccu8global_clk_vs" requiredSignalResource="global/clk">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:VirtualSignal" name="Global" evalFunction="" URI="http://www.infineon.com/1.0.18/app/ccu8global/1/ccu8global_globalsignal_vs" requiredSignalResource="global/global_signal">
    <defaultValue xsi:type="ResourceModel:Blocked" value="Blocked"/>
    <localValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="Blocked"/>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Clock Frequency" evalFunction="&#xD;&#xA;        function ForwardMapping(){&#xD;&#xA;             var XMC13xx=SCM.getSoftwareId().substring(0,2).compareTo(&quot;13&quot;);  &#xD;&#xA;   &#x9;&#x9;&#x9; if(XMC13xx==0)&#xD;&#xA;&#x9;&#x9;&#x9; var Res2 = SCM.getResource(&quot;clkapp2/clk002_irPCLK&quot;);&#xD;&#xA;&#x9;&#x9;&#x9; else&#xD;&#xA;&#x9;&#x9;&#x9; {&#xD;&#xA;          &#x9; var Res2 = SCM.getResource(&quot;clkapp/clk001_iroActualFreqCCU&quot;);&#xD;&#xA;&#x9;&#x9;&#x9; var Res1 = SCM.getResource(&quot;clkapp/clk001_erwCCUClkEnable&quot;); &#xD;&#xA;             SCM.setIntValue(Res1,1);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;             var Clock = SCM.getDoubleValue(Res2);&#xD;&#xA;             &#xD;&#xA;         }&#xD;&#xA;        &#xD;&#xA;        function BackwardMapping(){&#xD;&#xA; &#x9;&#x9;&#x9;var XMC13xx=SCM.getSoftwareId().substring(0,2).compareTo(&quot;13&quot;);  &#xD;&#xA;   &#x9;&#x9;&#x9; if(XMC13xx==0)&#xD;&#xA;&#x9;&#x9;&#x9; var Res2 = SCM.getResource(&quot;clkapp2/clk002_irPCLK&quot;);&#xD;&#xA;&#x9;&#x9;&#x9; else&#xD;&#xA;             var Res2 = SCM.getResource(&quot;clkapp/clk001_iroActualFreqCCU&quot;);&#xD;&#xA;          &#xD;&#xA;             var Clock = SCM.getDoubleValue(Res2);&#xD;&#xA;            SCM.setDoubleValue(currentResource,Clock);    &#xD;&#xA;        }&#xD;&#xA;" URI="http://www.infineon.com/1.0.18/app/ccu8global/1/ccu8global_irclock" downWardmappedList="//@consumed.5" maxValue="78" minValue="0">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="40"/>
    <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../PWMSP002/1.0.32/pwmsp002_4.app#//@consumed.111"/>
    <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../PWMSP002/1.0.32/pwmsp002_5.app#//@consumed.111"/>
    <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../PWMSP002/1.0.32/pwmsp002_6.app#//@consumed.111"/>
    <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../PWMSP002/1.0.32/pwmsp002_7.app#//@consumed.111"/>
    <localValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <toolTipHelpDescription>This displays the Clock frequency for the CCU module.</toolTipHelpDescription>
  </provided>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/ccu8global/1/global">
    <downWardmappedList xsi:type="ResourceModel:ResourceGroup" href="../../CCU81/CCU81_1.dd#//@provided.0"/>
    <requiredResource uriString="peripheral/ccu8/*/global" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="function resourceCondition() {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;var value1 = Solver.getSoftwareId().substring(0,2).compareTo(&quot;13&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;if((value1  == 0 )) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  return false;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;return true;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;}" URI="http://www.infineon.com/1.0.18/app/ccu8global/1/clkapp">
    <downWardmappedList xsi:type="ResourceModel:App" href="../../CLK001/1.0.42/clk001_0.app#/"/>
    <requiredResource uriString="app/clk001/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="function resourceCondition() {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;var value1 = Solver.getSoftwareId().substring(0,2).compareTo(&quot;13&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;if((value1  == 0 )) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  return true;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;return false;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;}" URI="http://www.infineon.com/1.0.18/app/ccu8global/1/clkapp2">
    <requiredResource uriString="app/clk002/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" evalFunction="function resourceCondition() {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;var value1 = Solver.getSoftwareId().substring(0,2).compareTo(&quot;13&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;if((value1  == 0 )) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  return false;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;return true;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;}" URI="http://www.infineon.com/1.0.18/app/ccu8global/1/resetapp">
    <downWardmappedList xsi:type="ResourceModel:App" href="../../RESET001/1.0.14/reset001_0.app#/"/>
    <requiredResource uriString="app/reset001/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/ccu8global/1/clkapp/clk001_iroactualfreqccu" upWardMappingList="//@provided.2" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="78"/>
    <downWardmappedList xsi:type="ResourceModel:IntegerParameter" href="../../CLK001/1.0.42/clk001_0.app#//@provided.35"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="78"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/ccu8global/1/clkapp/clk001_erwccuclkenable" upWardMappingList="//@provided.2" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="1"/>
    <downWardmappedList xsi:type="ResourceModel:EnumerationParameter" href="../../CLK001/1.0.42/clk001_0.app#//@provided.34"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="1"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/ccu8global/1/clkapp2/clk002_irpclk" isSystemDefined="true"/>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/ccu8global/1/global/global_signal" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU81/CCU81_1.dd#//@provided.1"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.18/app/ccu8global/1/global/clk" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CCU81/CCU81_1.dd#//@provided.2"/>
  </consumed>
  <propertyConstants name="uridevice" value="device">
    <propertyConstants name="uriCCUGlobal" value="app/ccuglobal/"/>
  </propertyConstants>
  <categoryDescription description="Peripheral related Apps" name="Peripheral Specific Apps">
    <subCategory description="Timer-Capture-Compare" name="Timer-Capture-Compare">
      <subCategory description="CAPCOM8" name="Capture/Compare Unit 8 (CAPCOM8)"/>
    </subCategory>
  </categoryDescription>
  <manifestInfo version="1.0.18">
    <keywords>ccu8 global</keywords>
    <keywords>CCU8GLOBAL</keywords>
    <keywords>Global</keywords>
    <keywords>SHARABLE</keywords>
    <properties xsi:type="ResourceModel:AppProperties_1_0" initProvider="true"/>
  </manifestInfo>
  <datagenerate fileName="CCU8GLOBAL_Conf.c" templateFileName="CCU8Global_Confc.jet"/>
  <datagenerate fileName="CCU8GLOBAL.c" templateFileName="CCU8Global.cdt" templateEngine="NONE" fileAction="COPY"/>
  <datagenerate fileName="CCU8GLOBAL.h" fileType="HFILE" templateFileName="CCU8Global.hdt" templateEngine="NONE" fileAction="COPY"/>
  <datagenerate fileName="CCU8GLOBAL_Conf.h" fileType="HFILE" templateFileName="CCU8Global_Confh.jet"/>
  <datagenerate fileName="CCU8GLOBAL_Extern.h" fileType="HFILE" templateFileName="CCU8Global_Externh.jet"/>
  <connections sourceSignal="clkapp/clk001_ccu_fccu_vs" targetSignal="app/ccu8global/1/ccu8global_clk_vs" constraintFunction="function resourceCondition() {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;var value1 = Solver.getSoftwareId().substring(0,2).compareTo(&quot;13&quot;);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;if((value1  == 0 )) {&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;  return false;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;return true;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;}"/>
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
  <softwareIdList>13.0102.7</softwareIdList>
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
  <softwareIdList>13.0101.10</softwareIdList>
  <softwareIdList>13.0101.11</softwareIdList>
  <softwareIdList>13.0102.10</softwareIdList>
  <softwareIdList>13.0102.11</softwareIdList>
  <softwareIdList>13.0102.9</softwareIdList>
</ResourceModel:App>
