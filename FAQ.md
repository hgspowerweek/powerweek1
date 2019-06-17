## Frequently asked questions

Collaborative place to collect information about the power week

* Is there a special terminal command for a pull-request?

  * git by itself does not know about pull-requests. This is a concept of github. Github
    offers command line tools called `hub` which should support opening a pull request from the command line.

* Does my Fork need to have the same files as the "original" repository, when I am 
  creating a pull request? (in other words can my fork contain additional files which
  I don't want to be merged to the original repo?)
  
  * This is not possible, as a pull request tries to integrate all commits/changes not yet on the target branch. But
    you could make a special branch that only contains the commits you want to have in the pull-request.
    To take out certain commits in that branch, one often uses `git rebase -i` (called interactive rebasing) which allows to       drop certain commits (advanced feature).
