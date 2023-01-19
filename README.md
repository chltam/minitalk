# minitalk

`sigaction` vs `signal` https://stackoverflow.com/questions/231912/what-is-the-difference-between-sigaction-and-signal

```
struct sigaction {
  void     (*sa_handler)(int);
  void     (*sa_sigaction)(int, siginfo_t *, void *);
  sigset_t   sa_mask;
  int        sa_flags;
  void     (*sa_restorer)(void);
           };

```

https://bitwisecmd.com
