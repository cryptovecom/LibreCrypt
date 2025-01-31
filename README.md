<LINK href="docs/styles_common.css" rel="stylesheet" type="text/css">
<LINK rel="shortcut icon" href="src/Common/Common/images/DoxBox.ico" type="image/x-icon">

<SPAN CLASS="master_link">
[![LibreCrypt logo](src/Common/Common/images/DoxBox128.png)](http://LibreCrypt.tdksoft.co.uk/)
</SPAN>
<SPAN CLASS="master_title">
_[LibreCrypt](http://LibreCrypt.tdksoft.co.uk/): Open-Source disk encryption for Windows_
</SPAN>


<DIV class="download-group">
<BUTTON class="download">
<a href="https://github.com/t-d-k/doxbox/releases/download/v6.2-beta/InstallLibreCrypt_v62Beta.exe">Download</a>
</BUTTON> 
</DIV>
<DIV class="download-group">
<BUTTON class="download-alt">
<a href="https://github.com/t-d-k/doxbox/releases/download/v6.2-beta/LibreCryptExplorer_v6.2.zip">Download LibreCrypt Portable</a>
</BUTTON>
</DIV>

<a href="https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=LCU9BEH4GM92N">
## Please support with the recommended amount of $15 or £10 
[![PayPal – The safer, easier way to pay online.](src/Common/Common/images/btn_donate_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=LCU9BEH4GM92N)
</a>


[Where your donation goes](https://github.com/t-d-k/LibreCrypt/blob/master/docs/donations.md)

<!---form action="https://www.paypal.com/cgi-bin/webscr" method="post" target="_top">
				<input type="hidden" name="cmd" value="_s-xclick">
				<input type="hidden" name="hosted_button_id" value="46ZWWMACF42MG">
				<input type="image" src="https://www.paypalobjects.com/en_US/GB/i/btn/btn_donateCC_LG.gif" border="0" name="submit" alt="PayPal – The safer, easier way to pay online.">
				<img alt="" border="0" src="https://www.paypalobjects.com/en_GB/i/scr/pixel.gif" width="1" height="1">
			</form 
			--->
## 	Project          Status
**An update on the project**  
_Firstly I'd like to thank those who have donated. This has been enough to get an OV code signing certificate; so in the next release the installer and UI should be signed (perhaps not the drivers - see below)._  
*I understand bugs have not been fixed and not much progress made recently, and the many users deserve an explanation.*  

*There are fundamental issues in the drivers that mean that it is possible to get 'root' access on any machine that LibreCrypt is installed on from a user application - see  [Issue 38](https://github.com/t-d-k/doxbox/issues/38) and  [Issue 39](https://github.com/t-d-k/doxbox/issues/39) (if secure boot is off). I cannot recommend using LibreCrypt with these bugs.    
Fixing these issues would involve re-architecturing the drivers, basically rewriting the main DLLs from scratch.  
This is compounded by the fact that there is no driver signing certificate (EV cert), MS wants to review the code to issue an EV cert - and the drivers would not pass with the current vulnerabilites (you would hope).  
In addition the encryption code in the drivers is old and is slow compared to modern implementations.*  

*OTOH, LibreCrypt is the only way to read LUKS volumes on Windows that I know of, and the user interface is the most friendly of the open-source OTFE applications (imho), so it would be a shame if it became obsolete.*  
*I believe the best way forward is to adopt the drivers from another open-source project with signed drivers like VeraCrypt or Diskcryptor, and modify them to support LUKS as well. This would mean two executables, one that would work with LUKS volumes, but would need a hack to run (as the current LibreCrypt), and another that would run out-of-the-box, but would not open LUKS volumes.*   
*I would of course review the new drivers for any obvious security issues.*  
*Meanwhile I'll fix the bugs relating to the UI, documentation etc. and mark the driver bugs as 'pending'.* 

*regards*  
*tdk (tom kelsey)*  
##	Features

* Full transparent encryption, containers appear as removable disks in Windows Explorer.
* Compatible with Linux encryption: dm-crypt and LUKS. Linux shell scripts support deniable encryption on Linux.
* Explorer program lets you browse containers when you don't have administrator permissions.
* Supports smartcards and security tokens.
* Encrypted containers can be a file, a partition, or a whole disk.
* Opens legacy volumes created with FreeOTFE
* Runs on Windows Vista onwards (see note below for 64 bit versions).
* Supports many hash (including SHA-512, RIPEMD-320, Tiger) and encryption algorithms (Including AES, Twofish, and Serpent) in several modes (CBC, LRW, and XTS).
* Optional 'key files' let you use a thumb-drive as a key.
* Portable mode doesn't need to be installed and leaves little trace on 3rd party PCs (administrator rights needed).
* Deniable encryption in case of 'rubber hose cryptanalysis'.
* Considered the most easy to use encryption program for Windows.

**Please note this is a Beta version with some known limitations. Particularly on 64 bit Windows the text 'Test Mode' is shown on the desktop.**
	
## New in version v6.3β

 	* Simplified open and create container dialogs by removing 'hidden' containers options
 	* Creating hidden containers is now through separate dialogs, which is easier and less error prone 
	* Added experimental feature to create LUKS containers
	* Minor UI improvements, including the option to remember the window position
	* Reviewed and simplified all the text used in the application to use less technical language
  * A new menu time shows the recommended 'hidden' offset, so hidden containers can be used without memorizing a number
  * More clearly separated LUKS and dm-crypt options in the UI, to prevent LUKs containers being accidentally opened as dm-crypt  
 
  
## New features in version 6.2β

 * Change of name to 'LibreCrypt'
 * Many UI bugs fixed - see [Issue 20](https://github.com/t-d-k/doxbox/issues/20)
 * Improved support for GPT partitioned discs.
 * Improved new password dialog.
 * Improved partition information when running as non-admin.

## Release notes
*Important: LibreCrypt in Portable mode will not work on Windows Vista and later 64 bit versions without a extra step before use.*

	* LUKs partitions on LVM volumes, or LVM volumes in LUKS partitions cannot be accessed due to Windows limitations
	*	To run in portable mode, you need to have admin rights.
	*	LibreCrypt does not support encryption of the operating system partition, for this we recommend Ubuntu Linux or DiskCryptor.

*LibreCrypt installed on Windows Vista and later 64 bit versions adds the text "Test Mode" to the Windows desktop. Please see the documentation for details on removing this.*

### Known bugs

	* LibreCrypt cannot access LVM containers without an additional filesystem driver that understands LVM. No such filesystem driver exists for Windows versions later than XP
	* LibreCrypt cannot access ext2,3,4 volumes without an additional filesystem driver that can read ext2.
	* Installing the LibreCrypt drivers may enable malware specifically written to take advantage of it to access files as administrator [see issue #38](https://github.com/t-d-k/LibreCrypt/issues/38)  
	* LibreCrypt may not be able to access internal disks where a LUKS volume was created using the whole volume, instead of a partition [see issue #30](https://github.com/t-d-k/LibreCrypt/issues/30)   

### Installing

	* On Windows 8 please turn off 'Safe Boot' and disklocker before installing.
	* There has been a report that Kaspersky anti-virus falsely reports LibreCrypt as having the 'generic.Trojan' virus, please disable or replace this before installing.

	* Please follow these instructions to run LibreCrypt in portable mode on 64 bit Windows; if you do not do this you will get the error "Windows requires a digitally signed driver" when starting the drivers. There is no need to do this if LibreCrypt is installed.
		+ Start LibreCrypt, click 'No' on the prompt to start the portable drivers, and 'OK' on the warning dialog about not having any loaded drivers.
		+ Click the Tools->"Allow Test-signed drivers" menu item.
		+ Reboot	
		+ After rebooting the words "Test Mode" appear in the four corners of the Desktop. Please see the documentation for details on removing this.
		
	* LibreCrypt needs to be run as administrator the first time it is run. After that it can be run as an ordinary user. 

#### Upgrading

	* This release has changes to the drivers, if upgrading from previous versions of LibreCrypt,DoxBox or FreeOTFE please completely uninstall the old version first
	*	Support for the following cyphers will be removed in a future version, please convert to another: xor, plain, single DES. Ditto for the 'plain' hash. 
	* Backwards compatibility with older versions of FreeOTFE (before 5.21) will be removed in version 6.3. Please convert any FreeOTFE volumes. This can be done by creating a new 'container' and copying the files across.

####	Passwords
*These issues relate to passwords (keyphrases) containing non-ASCII characters, e.g. accented letters and non Latin scripts, not to ASCII special characters like '$&^'.*

*	The handling of keyphrases containing non-ASCII characters will change in a future version. This change will not be backwards compatible. So in this version it is recommended to use only ASCII characters in keyphrases.
*	There are possible bugs in opening volumes created with FreeOTFE with non-ASCII characters. If you experience problems, please use the legacy app to change the password to an ASCII one and retry. Alternatively move the files to a native container.

For more details, please see the [getting started guide](http://LibreCrypt.tdksoft.co.uk/getting_started.html) and [FAQ](http://LibreCrypt.tdksoft.co.uk/FAQ.html).
 
