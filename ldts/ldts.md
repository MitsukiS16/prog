# LDTS

> Laboratório de Desenho e Teste de Software :)

---

## :heart: **Week**

<p align="center">
  <a href="#arrow_right-week-1">Week 1</a> •
  <a href="#arrow_right-week-2">Week 2</a> •
  <a href="#arrow_right-week-3">Week 3</a> 
</p>

## :heart: **Info**
<p align="center">
  <a href="#arrow_right-git">Git</a> • 
  <a href="#arrow_right-java">Java</a> 
</p>

---

### :arrow_right: **Week 1**

- [X] LDTS 2022-2023
- [ ] Git
  - [X] Leaning git branching
- [ ] Git vs Github

### :arrow_right: **Week 2**

- [ ] Java
- [ ] Lab Tutorial: GitHub
- [ ] Projeto Intelij

### :arrow_right: **Week 3**

- [ ] Lab tutorial: Java and Gradle (1/2)

Notes: JDK >= 17

---

### :arrow_right: **Git**

> Professor: André Restivo
>
> Index: Introduction Git-Basics Local Branches Remotes Reverting Workflows More


*VCS*
Version Control Systems

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






---

### :arrow_right: **Java**

idkk