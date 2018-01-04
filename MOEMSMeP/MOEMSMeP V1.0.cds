<distribution version="10.0.1" name="MOEMSMeP V1.0" type="MSI64">
	<prebuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></prebuild>
	<postbuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></postbuild>
	<msi GUID="{106778D9-9F78-47CB-96E1-E25353D7157B}" x64="true">
		<general appName="MOEMSMeP V1.0" outputLocation="d:\0_Daten\Singh_aktuell\MOEMSMePTest\cvidistkit.MOEMSMeP V1.0" relOutputLocation="cvidistkit.MOEMSMeP V1.0" outputLocationWithVars="d:\0_Daten\Singh_aktuell\MOEMSMePTest\cvidistkit.%name" relOutputLocationWithVars="cvidistkit.%name" upgradeBehavior="1" autoIncrement="true" version="1.0.1">
			<arp company="%company" companyURL="" supportURL="" contact="" phone="" comments=""/>
			<summary title="" subject="" keyWords="" comments="" author=""/></general>
		<userinterface language="German" showPaths="true" readMe="" license="">
			<dlgstrings welcomeTitle="MOEMSMeP V1.0" welcomeText=""/></userinterface>
		<dirs appDirID="100">
			<installDir name="MOEMSMeP V1.0" dirID="100" parentID="24" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="[Program Files]" dirID="24" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="[Start&gt;&gt;Programs]" dirID="7" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="MOEMSMeP V1.0" dirID="101" parentID="7" isMSIDir="false" visible="true" unlock="false"/></dirs>
		<files>
			<simpleFile fileID="0" sourcePath="d:\0_Daten\Singh_aktuell\MOEMSMePTest\cvibuild.MOEMSMeP\Release64\MOEMSMeP.exe" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="1" sourcePath="d:\0_Daten\Singh_aktuell\MOEMSMePTest\MOEMSMeP_2010.uir" relSourcePath="MOEMSMeP_2010.uir" relSourceBase="0" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="2" sourcePath="d:\0_Daten\Singh_aktuell\MOEMSMePTest\settings.ini" relSourcePath="settings.ini" relSourceBase="0" targetDir="100" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="3" sourcePath="d:\0_Daten\Singh_aktuell\MOEMSMePTest\cvibuild.MOEMSMeP\Release64\MOEMSMeP.exe" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/></files>
		<fileGroups>
			<projectOutput64 targetType="0" dirID="100" projectID="0">
				<fileID>0</fileID></projectOutput64>
			<projectOutput64 targetType="0" dirID="101" projectID="0">
				<fileID>3</fileID></projectOutput64>
			<projectDependencies64 dirID="100" projectID="0"/></fileGroups>
		<shortcuts>
			<shortcut name="MOEMSMeP V1.0" targetFileID="0" destDirID="101" cmdLineArgs="" description="" runStyle="NORMAL"/></shortcuts>
		<mergemodules/>
		<products/>
		<runtimeEngine cvirte="true" instrsup="true" analysis="true" netvarsup="true" activeXsup="true" rtutilsup="true" installToAppDir="false"/>
		<advanced mediaSize="650">
			<launchConditions>
				<condition>MINOS_WINXP</condition>
			</launchConditions>
			<includeConfigProducts>true</includeConfigProducts>
			<maxImportVisible>silent</maxImportVisible>
			<maxImportMode>merge</maxImportMode>
			<custMsgFlag>false</custMsgFlag>
			<custMsgPath>c:\programme\national instruments\cvi2010\bin\msgrte.txt</custMsgPath>
			<signExe>false</signExe>
			<certificate></certificate>
			<signTimeURL></signTimeURL>
			<signDescURL></signDescURL></advanced>
		<Projects NumProjects="1">
			<Project000 ProjectID="0" ProjectAbsolutePath="d:\0_Daten\Singh_aktuell\MOEMSMePTest\MOEMSMeP.prj" ProjectRelativePath="MOEMSMeP.prj"/></Projects>
		<buildData progressBarRate="0.988937131165080">
			<progressTimes>
				<Begin>0.000000000000000</Begin>
				<ProductsAdded>0.055424500000000</ProductsAdded>
				<DPConfigured>4.680421000000000</DPConfigured>
				<DPMergeModulesAdded>7.180423500000000</DPMergeModulesAdded>
				<DPClosed>15.205415499999999</DPClosed>
				<DistributionsCopied>17.905425999999999</DistributionsCopied>
				<End>101.118662500000000</End></progressTimes></buildData>
	</msi>
</distribution>
