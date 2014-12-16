<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="NVIC_DMA001" description="App provides DMA module specific handling&#xA; of Interrupt events.This App is included by &#xA;top level DMA apps to register callback function&#xA; to handle DMAx Unit Interrupt Events." descriptionURL="/doc/html/group___n_v_i_c___d_m_a001_app.html" mode="SHARABLE" URI="http://www.infineon.com/1.0.20/app/nvic_dma001/2">
  <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../DMA003/1.0.18/dma003_9.app#//@consumed.2"/>
  <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../DMA003/1.0.18/dma003_10.app#//@consumed.2"/>
  <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../DMA003/1.0.18/dma003_11.app#//@consumed.2"/>
  <upWardMappingList xsi:type="ResourceModel:ProxyResource" href="../../DMA003/1.0.18/dma003_12.app#//@consumed.2"/>
  <provided xsi:type="ResourceModel:VirtualSignal" name="DMA Interrupt" URI="http://www.infineon.com/1.0.20/app/nvic_dma001/2/dma_int_vs" requiredSignalResource="nvicnodedma/signal_in">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Priority" evalFunction="&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;function ForwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = SCM.getResource(&quot;nvicnodedma/ipr_pri&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Intvalue = SCM.getIntValue(Res); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var BitShift = 2; &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var BitMask = 0x03; &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Intvalue1 = SCM.getIntValue(currentResource);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;Intvalue = (Intvalue &amp; BitMask) | (Intvalue1 &lt;&lt; BitShift);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(Res,Intvalue);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;function BackwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = SCM.getResource(&quot;nvicnodedma/ipr_pri&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Intvalue = SCM.getIntValue(Res); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var BitShift = 2; &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var BitMask = 0xFC; &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(currentResource,(Intvalue &amp; BitMask)>>BitShift);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;" URI="http://www.infineon.com/1.0.20/app/nvic_dma001/2/nvic_dma001_irwinterruptpriority" downWardmappedList="//@consumed.3" maxValue="3F" minValue="0">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0A"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0A"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="a"/>
    <toolTipHelpDescription>DMA interrupt priority</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:IntegerParameter" name="Subpriority" evalFunction="&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;function ForwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = SCM.getResource(&quot;nvicnodedma/ipr_pri&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Intvalue = SCM.getIntValue(Res); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var BitShift = 0; &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var BitMask = 0xFC; &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Intvalue1 = SCM.getIntValue(currentResource);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;Intvalue = (Intvalue &amp; BitMask) | (Intvalue1 );&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(Res,Intvalue);&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;function BackwardMapping()&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;{&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Res = SCM.getResource(&quot;nvicnodedma/ipr_pri&quot;); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var Intvalue = SCM.getIntValue(Res); &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var BitShift = 0; &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;var BitMask = 0x03; &#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;SCM.setIntValue(currentResource,(Intvalue &amp; BitMask));&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;&#x9;&#x9;}&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;" URI="http://www.infineon.com/1.0.20/app/nvic_dma001/2/nvic_dma001_irwinterruptsubpriority" downWardmappedList="//@consumed.3" maxValue="0" minValue="0">
    <defaultValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <localValue xsi:type="ResourceModel:StringValue" value="0"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="0"/>
    <toolTipHelpDescription>This configuration is for future use</toolTipHelpDescription>
  </provided>
  <provided xsi:type="ResourceModel:API" description="Function to configure DMA Interrupt priority and reset&#xD;&#xA;&#x9;&#x9;&#x9;&#x9;             all interrupt related registers to reset values" URI="http://www.infineon.com/1.0.20/app/nvic_dma001/2/nvic_dma001_init" APIName="NVIC_DMA001_Init">
    <localValue xsi:type="ResourceModel:StringValue" value="-1"/>
    <globalValue xsi:type="ResourceModel:StringValue" value="-1"/>
  </provided>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.20/app/nvic_dma001/2/nvicnodedma">
    <downWardmappedList xsi:type="ResourceModel:ResourceGroup" href="../../CPU/CPU_0.dd#//@provided.93"/>
    <requiredResource uriString="peripheral/cpu/0/nvic/interrupt/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.20/app/nvic_dma001/2/resetapp">
    <downWardmappedList xsi:type="ResourceModel:App" href="../../RESET001/1.0.14/reset001_0.app#/"/>
    <requiredResource uriString="app/reset001/*" uriType="LOCALTYPE"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.20/app/nvic_dma001/2/nvicnodedma/signal_in" isSystemDefined="true">
    <downWardmappedList xsi:type="ResourceModel:SignalDeclaration" href="../../CPU/CPU_0.dd#//@provided.94"/>
  </consumed>
  <consumed xsi:type="ResourceModel:ProxyResource" URI="http://www.infineon.com/1.0.20/app/nvic_dma001/2/nvicnodedma/ipr_pri" upWardMappingList="//@provided.1 //@provided.2" isSystemDefined="true">
    <localValue xsi:type="ResourceModel:IntegerValue" value="28"/>
    <downWardmappedList xsi:type="ResourceModel:BitField" href="../../CPU/CPU_0.dd#//@provided.95"/>
    <globalValue xsi:type="ResourceModel:IntegerValue" value="28"/>
  </consumed>
  <propertyConstants name="uriPeri_nvic" value="peripheral/cpu/0/nvic/">
    <propertyConstants name="uri_resetapp" value="app/reset001/"/>
  </propertyConstants>
  <categoryDescription description="Peripheral Specific Apps" name="Peripheral Specific Apps">
    <subCategory description="CPU-System" name="CPU-System">
      <subCategory description="NVIC (Nested Vector Interrupt Controller)" name="NVIC (Nested Vector Interrupt Controller)"/>
    </subCategory>
  </categoryDescription>
  <categoryDescription description="Service Apps" name="Service Apps">
    <subCategory description="Interrupt" name="Interrupt"/>
  </categoryDescription>
  <manifestInfo version="1.0.18">
    <keywords>DMA</keywords>
    <keywords>DMA Interrupt</keywords>
    <keywords>NVIC</keywords>
    <keywords>NVIC_DMA001</keywords>
    <properties xsi:type="ResourceModel:AppProperties_1_0" initProvider="true"/>
  </manifestInfo>
  <datagenerate fileName="NVIC_DMA001.h" fileType="HFILE" templateFileName="NVIC_DMA001.hdt" templateEngine="NONE" fileAction="COPY"/>
  <datagenerate fileName="DMA_Types.h" fileType="HFILE" templateFileName="DMA_Types.hdt" templateEngine="NONE" fileAction="COPY"/>
  <datagenerate fileName="NVIC_DMA001.c" templateFileName="NVIC_DMA001c.jet"/>
  <datagenerate fileName="NVIC_DMA001_Conf.c" templateFileName="NVIC_DMA001_Confc.jet"/>
  <datagenerate fileName="NVIC_DMA001_Conf.h" fileType="HFILE" templateFileName="NVIC_DMA001_Confh.jet"/>
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
  <softwareIdList>45.0204.2</softwareIdList>
  <softwareIdList>45.0204.3</softwareIdList>
  <softwareIdList>44.0.3</softwareIdList>
  <softwareIdList>44.00.5</softwareIdList>
  <softwareIdList>44.02.3</softwareIdList>
  <softwareIdList>44.02.5</softwareIdList>
  <softwareIdList>42.00.5</softwareIdList>
  <softwareIdList>42.0.6</softwareIdList>
  <softwareIdList>42.04.5</softwareIdList>
  <softwareIdList>42.04.6</softwareIdList>
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
</ResourceModel:App>
