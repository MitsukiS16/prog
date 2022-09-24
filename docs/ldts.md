# LDTS

```
 [Laboratório de Desenho e Teste de Software]
```

## :heart: **Week**
<p align="center">
  <a href="#arrow_right-week-1">Week 1</a> •
  <a href="#arrow_right-week-2">Week 2</a> •
  <a href="#arrow_right-week-3">Week 3</a> • 
  Week 4</a> • 
  Week 5</a> • 
  Week 6</a> • 
  Week 7</a>
</p>

## :heart: **Info**
<p align="center">
  <a href="#arrow_right-git">Git</a> • 
  <a href="#arrow_right-java">Java</a> • 
  Gradle</a> • 
  Tests</a> • 
  SOLID Principles</a> • 
  UML</a> • 
  Design Patterns</a> • 
  Refactoring and Code Smells</a>
</p>

----

### :arrow_right: **Week 1**

- [X] LDTS 2022-2023
- [X] Git
  - [X] Leaning git branching
- [X] Git vs Github

### :arrow_right: **Week 2**

- [ ] Java
- [ ] Lab Tutorial: GitHub
- [ ] Projeto Intelij

### :arrow_right: **Week 3**

- [ ] Lab tutorial: Java and Gradle (1/2)

Notes: JDK >= 17

----

### :arrow_right: **Git**

> Professor: André Restivo
>
> Index: Introduction Git-Basics Local Branches Remotes Reverting Workflows More


*VCS* [Version Control System]
> A system that records changes to a file or set of files over time, like revert selected files or a project, compare changes over time, see who modified, etc

> [[VIDEO] Version Control System Introduction](https://www.youtube.com/watch?v=zbKdDsNNOhg)


*Local VCS*
> Local VCS use a simples database that keeps all changes to files under revision control.
>
> Most store only the differences between files instead of copies of each version.
> 
> Example: RCS

> [[WEBSITE] Example Local VCS -> RCS](https://www.gnu.org/software/rcs/)


*Centralized VCS*
> A single server that contains all the versioned files.
>
> Users can checkout a particular file version.
> 
> Example: CVS, Subversion
> 
> Advantagens: everyone knows what everyone is doing; fine grained control over who can do what
> 
> Disadvantages: single point of failure; needs constant connectivity; backups are mandatory.

> [[WEBSITE] Example Centralized VCS -> CVS](hhttp://cvs.nongnu.org)


*Distributed VCS*
> All clients fully mirror the repository, including its full history
> 
> THere is no difference between a server and a client
> 
> BUt one, or more, computers can be used as a central point of synchronization
> 
> Example: Git, Mercurial, Bazaar, Darcs

> [[WEBSITE] Example Local VCS -> Git](https://git-scm.com)


*Characteristics:*

> Snapshots: does not story only the differences between versions of file. Instead, it saves them as a series of snapshots. But, if files have not changed, it does not store them again «
> 
> Local: Most Git operations are local.
> 
> Integrity: everything in git is checksummed before it is stored; everything is the referred to by that checksum; checksum example: 7e22343424wedadwdaw33e24222
> 
> Version: each version (commmit) is a snapshot of that version files. If not changed, file are just links to a previous version. All objecs (files, comiits,  ...) have an hash identifier.

*Git Areas*

> The git directory (.git) is where git sotres the metadata and object database for your project.
> 
> The working tree is a single checkout of one version of the project.
> 
> The staging area (or index) is a file in your Git directory that stores information about what will go into your next commit.

*File States*

> FIles in the working directory can be in different states.

*Local Git*

| Command | Utility |
|---|---|
| ``` cd project ``` | Enter a local directory. |
| ``` git init ``` | Turn it into a git repository (this will create an hidden .git subdirectory containing all of your necessary repository files). |
| ``` git add README``` | Track and stage a file that is currently not tracked by Git and stage a file that has been modified. |
| ``` git add -A ``` or ``` git add --all ``` | Flag to stage all untracked or modified files. |
| ``` git commit ``` or ``` git commit -m ``` | Records a new snapshot to the repository. | 
| ``` git commit -am ``` or ``` git commit -a -m ``` | Automatically stages anymodified (tracked) files. | 
| ``` git status ```  | Determine which files are in which state.  |
| ``` git status -s ``` | The --short flag can be used to get a more concise output. First column has info about the staging area and the second has info about the working directory.  |
| ``` git rm README ``` | Remove the file from the working directory and staging that change at the same time. (instead of elimiting the file and then adding the changes you just remove) 
| ``` git log ``` | Allows you yo see the commit history of a repository. We can see by **whom** and **when** each commit was made and the commit **message** and the **hash** of each commit. |
| ``` git log --oneline``` or ``` git log --oneline -1 ``` | Simplified version of the log. |
| ``` git log -1 -p ``` | The --patch flag shows the difference introduced in each commit. |
| ``` git branch ``` | Show the current local branches. The __*__ represents the HEAD.  |
| ``` git branch <namebranch> ``` | Create a branch (only creates, does not move the HEAD) |
| ``` git checkout <namebranch> ``` | Change to another branch |
| ``` git checkout -b <namebranch> ``` | Create and checkout a new branch |
| ``` git checkout master ``` | Checkout the master branch: the head moves to the commit pointed by the master branch and the files are reverted to the snapshot that master points to |
| ``` git merge <namebranch> ``` | Git merges the identified branch into the current branch.  | 
| ```git branch -d <namebranch> ``` | Delete a branch you do not longer need. Deleting a branch leaves all commits alone and only deletes the pointer. |
| ``` git clone https://..... ``` | clone another repository |
| ``` git remote -v ``` | List our remotes. Git named our remote origin and set it up for both fetching and pushing data. |
| ``` git remote add <nameremote> https://..... ``` | Add remote and give a name |
| ``` git checkout --track origin/feature ``` | Creates a local feature branch |
| ``` git pull origin master ``` | Fetches and merges origin/master |
| ``` git pull ``` | Fetches data from the server you originally cloned from and automatically tries to merge it into the code you are currently working on. |
| ``` git push ``` | Pushes local modifications to a remote. (Only fast-forward merges are allowed) |
| ``` git reset --hard ``` | Discard all local changes - Does not touch the index file or the orking tree at all. |
| ``` git reset --soft ``` | Discard all local changes - Resets the index and working tree. |
| ``` git reset --mixed ``` | Discard all local changes - Resets the index and working tree **(default mode)**. |
| ``` git reset HEAD <file> ``` | Unstage changes to a single file |
| ``` git reset --hard <commit-id> ``` | Revert changes already commited but not pushed to a remote. |
| ``` git revert <commit-id> ``` | Revert changes already commited and pushed to a remote. Introduce the changes needed to revert the ones done by the commit without deleting the commit from history. |
| ``` git config --global user.name ``` | Add name, for you commits have your name attached to them |
| ``` git config ---global user.email ``` | Add email, for you commits have your email attached to them |
| ``` git rebase master ``` | MOve the entire feature branch to start from the tip of the master branch by rewriting the project history and creating brand new commits for each commit in the original branch. | 



*Partially Staged Files*
> A FIle can be partially staged
> 
Example1: 
``` 
$ git commit -m "Added some text"      # Commiting initial edit
$ git status -s
 M README                              # File now still has changes
$ git add README                       # Staging those changes
M  README
$ git commit -m "Added another text"   # Commiting following edits
```
Example2: 
``` 
$ git add README                               # Staging following changes
$ git status -s
A  README                                      # All changes staged
$ git commit -m "Added some and another text"  # Commiting both changes at once
``` 

*Commits*
> Files are stored as blobs and identified by an hash.
> 
> Versions (or commits) are just a snapshot, also identified by and hash, poiting to a series of blobs.
> 
> Each commit contains the author's name and email address, the message that was typed, and pointers to the commit that directly came before this commit (its parent(s))

*Branches*
> A branch is a Git simply a lightweight movable pointer to one of theses commits.
> >
> The default branch name in Git is master.
>
> As you start making commits, you're given a master branch that points to the last commit you made.
> 
> Every time you commit, the current branch pointer moves forward automatically.

*Head*
> GIt uses a special pointer called Head that always points to your current branch.

*Merging*
> Git usas two main strategies to merge branches: Fast-forward merge (no divergent work) & Three-way merge (divergent work)
> 
> Fast-forward Merge: when you merge one commit with a commit that can be reached by following the first commit's history because there is no divergent work to merge together - git just moves the branch pointer forward.
> 
> Three-way Merge: when the commit on the branch you're on ins't a direct ancestor of the branch you're merging in - git uses the two snapshots pointed to by the branch tips and the common ancestor of the two to create a new commit.
> 
> Git merge - you create a new ‘merge commit’ in your feature branch, which is a  on-destructive operation that ties the histories of both branches. This preserves the exact history of your project. The branch that you merge will always have an extraneous merge commit that will be tracked every time you need to incorporate upstream states. This can lead to muddling the history of your branch, thereby making it more difficult for yourself or other developers to track the history of changes using `git log` and/or roll back to previous states.

*Conflits*
> If you changed the same part of the same file differently in the two branches you're merging, Git won't be able to merge them cleanly - "Automatic merge failed; fix conflicts and then commits the result"
> 
> You can use the satus command to see which files have conflicts.

*Revolving conflicts*
> Editing the file with confilcts we can see the conflict;
> 
> To solve it we just have to edit the file and commit the merge.

Example1: 
``` 
This is a README file
<<<<<<< HEAD
This was added in the master branch
=======
This was added in the testing branch
>>>>>>> testing
```
```
This is a README file
This was added in the master branch
This was added in the testing branch
```

*git ignore*
> A .gitignore file specifies intentionally untracked files that git should ignore. Files already tracked by git are not affected.
> 
> Each line in a .gitignore file specifies a pattern
> 
> What files to ignore: not used by your project; not used by anyone else; generated by another process

*Remotes*
> Remote reporitories are versions of your project that are hosted elsewhere (another folder, local network, etc)
> 
> You can ``` push ``` and ``` pull ``` data to and from remotes.
> 
> The easist way to end up with a remote, is to clone another repository.
> 
> Besides the origin remote from where we cloned our project, we can add more remotes.

*Protocols* 
> Git can use four major network protocols to transfer data to and from remotes:
> 
> - Local: Useful if you have access to a shared mounted directory
> 
> - Git: A special daemon that comes packaged with git. (ssh but without authentication or encryption).
> 
> - SSH: The most commonly used protocol.
> 
> - HTTP: Easiest to setup for read-only scnearios but very slow.

*Fetching*
> Fetching gets all the data from a remote project that you don't have yet.
> 
> After fetching, you will also have references to all the branches from that remote.
> 
> Fetching only downloads the data to your local repository. It doesn't automatically merge it with any of your work or modify what you're currently working on. 

*Tracking Branches*
> Tracking branches are local branches that have a direct relationship to a remote branch.
> 
> When you clone a repo, it generally automatically creates a master branch that tracks origin/master.

*Git Hosts*
> Some free git hosts you can use: GitHUv, BitBucket, GitLab, SourceForge

*Relative commits*
> The ~(tilde) and ^(caret) symbols are used to point to a position relative to a specific commit.
> 
> COMMIT^ refers to the previous commit to COMMIT
>
> COMMIT^^ refers to the previous commit to COMMIT^
> 
> COMMIT~2 refers to two commits before to COMMIT.

*Workflows*
> There are endless different ways to use Git: 
> 
> - having feature branches for each new feature; 
> 
> - having release branches where releases can be maintained; 
> 
> - hot fix branches to quickly patch produciton releases

*More stuff*
> Tags - Really just unmovable branches. Useful for marking releases
>
> Rebase - A different way to merge.
> 
> Hooks - IFTTT for Git.
> 
> Blame - WHo broke the code?
> 
> Bisect - Finding a bad commit.
>
> Stash - Save these changes for later.
> 
> Pull requests - Ask to take my code.

*Git vs Github*
> Git: VCS designed to make it easier to have multiple versions of a code base.
> 
> Github: websire that hosts git repo on a remote server. Hosting repo on Github facilitates the sharing of codebases among teams by providing a GUI to easily fork or cloe repo to a local machine.

*Connecting git with Github*
> In order to prevent having to enter your password each time you push up to Github, you must configure git and Github to recognize Secured Shell (SSH) keys that you generate.
> 
> To check and see if you have any recognized SSH keys active on Github, go to https://github.com/settings/keys
> 
> If you do not see any SSH keys listed, you do not have SSH configured with Github. We can assist with this later.
> 
> If using Mac OS X, you can also configure your keychain to automatically enter your password via HTTPS.

*Merging vs Rebasing*
> From a conceptual standpoint, git merge and git rebase are used to achieve the same ultimate goal: to integrate changes from one branch into another branch. There are, however, distinct mechanics to both methods.

*Git rebase*
> Singular history with no forking of the commit history.
> 
> Because rebase rewrites project history, you love the context provided by a merge commit, you won't be able to see when upstream changes were actually integrated into the feature branch. 
> 
> You could potentially cause extreme difficulty by rebasing master to the tip of yout feature branch, leading git to think that your master branch's history has diverged from the rest.
> 
> In doing so, everyone else would still be working from the original master branch, and both masters would need to be merged together. 

*Merge conflicts*
> Merge conflicts arise when two members of the same development team work on the same file and try to merge in their respective changes. 
>
> The proper way to avoid merge conflicts would be to ensure that only one branch is fully committed, pushed, and merged to master, allowing the other branch to integrate any changes before  ttempting to push and merge to master.


----

### :arrow_right: **Java**

idkk