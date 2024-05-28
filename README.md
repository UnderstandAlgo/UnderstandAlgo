# Prototyping state

**Todo**\
prototype website
reasearch frameworks for visuals
add contents
# Testing
There may be some issues with VCS and stale CMake data per version.

To fix this I followed these steps:
1. Initialize and Update Git Submodules: These commands initialize, update, and ensure the recursive update of all the submodules of your repository.
```
git submodule init
git submodule update
git submodule update --init --recursive
```
2. Back up the cmake-build-debug directory: I backed up the cmake-build-debug directory to prevent any data loss. This involved creating a new backups directory in my home directory:
```
mkdir ~/backups
cp -r cmake-build-debug ~/backups/cmake-build-debug_backup
```
3. Delete the cmake-build-debug directory: I deleted the stale cmake-build-debug directory. This directory is generated automatically by CLion when you build your project. There may have been an issue with the initial cmake-build-debug directory, and deleting it allows CLion to generate a new one from scratch.

```rm -rf cmake-build-debug```

4. Re-run the CMake process and rebuild the project: In CLion, I refreshed the CMake project and rebuilt the project. This would regenerate the cmake-build-debug directory and recompile your code.


# UnderstandAlgo

General plan for the strucuture of this repo:

Data Strucures\
&emsp;Static\
&emsp;&emsp;Array\
&emsp;&emsp;&emsp;C\
&emsp;&emsp;&emsp;C++\
&emsp;Dynamic\
&emsp;&emsp;Tree\
&emsp;&emsp;&emsp;-\
&emsp;&emsp;&emsp;-\
&emsp;&emsp;&emsp;-\
Algorithms\
&emsp;sorting\
&emsp;&emsp;-\
&emsp;&emsp;-\
&emsp;searching


<details><summary>

[Algo](Algorithms)

</summary>

Algos

</details>
