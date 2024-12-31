---
layout: default
course_number: CS335
title: Lab Setup
---

# Install SEED VM on VirtualBox 6.x

### Account Information of this VM

- User name: ```seed```
- Password: ```dees```

### Preparation

Before installing the SEED VM, please do the following:

- Install the free [Oracle® VM VirtualBox](https://www.virtualbox.org/) software first.
  - The VM has been tested on Version `6.x`.
  - VirtualBox is a general-purpose full virtualizer for x86 hardware, targeted at server, desktop and embedded use. User Manual can be found [here](https://www.virtualbox.org/manual/).

- Download the zip file `SEED-Ubuntu20.04.zip` from the
[Google Drive](https://drive.google.com/file/d/138fqx0F8bThLm9ka8cnuxmrD6irtz_4m/view?usp=sharing) or [DigitalOcean](https://seed.nyc3.cdn.digitaloceanspaces.com/SEED-Ubuntu20.04.zip), unzip it,
and you will get a `.vdi` file. This file contains the pre-built SEED
Ubuntu 20.04 image. This document shows how to build a virtual machine
using this image.


### Step 1: Create a New VM in VirtualBox

We need to use `New` to create a new virtual machine.

![New VM](images/vm-new.png)

### Step 2: Provide a Name and Select the OS Type and Version

Our prebuilt Ubuntu 20.04 VM is 64-bit, so pick Ubuntu (64-bit).

![name and OS type](images/vm-name-type.png)


### Step 3: Set the Memory Size

We need to allocate dedicated memory for the VM.
1024 MB should be sufficient, but we recommend 2GB. If your computer has more
RAM, you can increase accordingly. The more memory you give to the VM,
the better the performance you will get.

![memory](images/vm-memory.png)

### Step 4: Select the Pre-built VM File Provided by Us

Click the folder image. On the popup window, use
the `Add` button to select the `.vdi` file downloaded
from the SEED website.

![choose vdi](images/vm-hard-disk.png)

**Note**: If you get an error message saying that the UUID already exists,
this is because the UUID in the selected `vdi` file is the same as the
one used by an existing VM. You can either remove the other VM or
[change the UUID](https://tecadmin.net/change-the-uuid-of-virtual-disk/)
in the `vdi` file.

### Step 5: Configure the VM

After the previous step, your VM will be created, and you will
see it on VirtualBox's VM panel. We need to do some further
configuration. Right-click the M, click
the `Settings` option, and we will see the Settings window.

![finished](images/vm-setting.png)


#### Step 5.a: Enable Copy and Paste

Go to the `General` category, and select the `Advanced` tab.
Select `Bidirectional` for both items. The first item allows users to copy
and paste between the VM and the host computer
The second item allows users
to transfer files between the VM and the host computer using Drag'n Drop (this
feature is not always reliable).

![general](images/vm-setting-general.png)

The copy-and-paste feature is very useful. If you can't do copy and paste,
chances are that you forgot to do this step. You can always do it later
by selecting the `Devices` menu item, and you will see the
`Shared Clipboard` submenu.


#### Step 5.b: CPUs

Go to the `System` category, and select the `Processor` tab.
Assign number of CPUs to this VM if you prefer. Although may be sufficient,
if the performance seems to be an issue, increase the number.

![CPU cores](images/vm-setting-system.png)

#### Step 5.c: Display

Go to the `Display` category, and select the `Screen` tab. If the
display does not seem to work properly, try to increase the amount of video memory.
In our testing, `28 MB` seems to be sufficient.

![display](images/vm-setting-display.png)

**Note 1**: Make sure to select `VMSVGA`, as choosing other graphic controllers
may lead to the crash of the VM.

**Note 2**: If your computer's screen resolution is too high, the VM may not be able
to match the high resolution. As results, your VM will be very small on your screen.
To make it bigger, adjust the `Scale Factor` in this setting.

#### Step 5.d: Network

Go to the `Network` category, and select the `Adapter 1` tab. We will
choose the `NAT Network` adaptor. Click the `Advanced` drop-down menu to
further configure the network adaptor. If you don't see such an adaptor,
see the note below.

![display](images/vm-setting-network.png)


**Note**: If you don't see the `NAT Network` adaptor, you need to create one.
Go to the `File` menu, click `Preferences...`. You will see a popup window.
Go to the `Network` tab, and you can add a new `Nat Network` adaptor there.

### Appendix A: Start the VM and Take Snapshot

We can now start the VM. You can also use the `Take` button to take a snapshot
of your VM. This way, if something goes wrong, you can roll back the state of
your VM using the saved snapshots.

![display](images/vm-start.png)

### Appendix B: Stop the VM

There are many ways to stop the VM. The best way is to use the `Save State`. This
is different from shutting down the VM. It saves the current VM state, so next time
when you restart the VM, the state will be recovered. Moreover, the speed is also
faster than booting up a VM.

![display](images/vm-stop.png)

### Appendix C: Creating a Shared Folder

Sometimes, we need to copy files between the host machine and the VM.
If you are using the VM from the cloud, you can see our cloud VM manual
for instructions. Or, you can just use a cloud storage service, such as
Dropbox and Google Drive to share files between your VM and host machine.

If you run the VM on your local computer, you can create a shared folder
between your computer and the VM.

**Step A.** First you need to create a folder on your local computer (or using
an existing folder). We will let the VirtualBox know that this folder
should be shared with the VM. Go to the following menus:

![Shared Folder](images/vm-shared-folder.png)

Once you see a `Add Share` popup window, select the folder that
you want to share, click OK, and you will see that the folder is now
made available for sharing.

![Shared Folder](images/vm-shared-folder-2.png)

**Step B.** Inside the VM, we need to mount the shared folder somewhere.
Let's mount it to the home directory as a folder `Share`.
We will create a folder called `Share` in the home directory, and then
mount the shared folder `VM_Shared` to this `Share` folder using
the following command. After that, you can access the shared folder
from `~/Share`.

```
$ mkdir -p ~/Share
$ sudo mount -t vboxsf VM_Shared ~/Share
```

**Important Note.** Please only use the shared folder to copy files
between the VM and the host machine, and **never use it
as your working folder**. Working from the shared folder has
caused many problems, especially on the permissions of the files
created inside the shared folder. For example, if we unzip
the `Labsetup.zip` file inside the shared folder, the permissions
of the unzipped files will be different from those on
the original files. Some labs and containers are very
sensitive to those permissions.


### Troubleshooting

- The first thing you should do after creating your SEED VM is to update your packages; to do that, run the following two commands from your VM:
  - ```sudo apt update``` - this commands downloads package information from all configured sources
  - ```sudo apt upgrade``` - will upgrade all installed packages to their latest versions
- If the guest screen is too small:
  - With VirtualBox 6.0.0 you need to go to the VirtualBox Preferences » Display » Scale Factor = 200%.
- When you clone your VM's, make sure the MAC Address Policy is set to _Generate new MAC addresses for all network adapters_.
  