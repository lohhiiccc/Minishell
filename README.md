# Minichel

## build-in:
* ### **echo**
  * ``echo`` ``[option]`` - display all arg(s)
    * ``-n`` do not output the trailing newline

     ```bash
     $ echo salut
     salut
     $ echo -n salut
     salut$ 
     ```
* ### **pwd**
  * ``pwd`` - print current working directoey
    ```bash
    $ pwd
    /home
    ```
* ### **cd**
  * ``cd`` ``[opt/path](optional)`` - change the working directory
    * ``-`` => ``cd $OLDPWD``
    * ``path`` => ``cd path``
    * ``nothing`` => ``cd $HOME``
    ```bash
    $ pwd && cd .. && pwd
    /home/loic/Documents/Minishell
    /home/loic/Documents
    $ cd - && pwd
    /home/loic/Documents/Minishell
    ```
* ### **env** 
  * ``env`` - display environement variable
* ### **unset**    
  * ``unset`` ``[var]`` - unset var from env
    ```bash
    $ unset PWD
    $ echo -n |$PWD|
    ||$
    ```
* ### **export**
  * ``export`` ``[varname]=[value]``
     ```bash
    $ export arg='export test'
    $ env | grep arg
    arg=export test
     ```
* ### **return**
  * ``return`` ``[integer](optional)`` - do nothing and return the first argument
    ```bash
    $ return
    $ echo -n $?
    0$ return 5 || echo value: $?
    value: 5
    ```
* ### **exit**
  * ``exit`` ``[value](optional)`` - exit shell and return value
 
  
## 🙇 Author
#### [Rio Loic](https://github.com/lohhiiccc) [(Lrio)](https://profile.intra.42.fr/users/lrio)
#### [Juffard Michel](https://github.com/MichJuffard) [(Mjuffard)](https://profile.intra.42.fr/users/mjuffard)
