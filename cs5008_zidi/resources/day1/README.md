# Setting up Emacs

There are a number of things we can do to setup Emacs and vim to make them better 
environments to write our code. 

I'm including some basic things. Just below are some instructions that will set up 
your environment to be just like mine. Below that, I go into more details about what 
exactly I've done, so you can be a bit more judicious about what you take or don't take :) 

* Pull this repo to the Khoury machine or your VirtualBox machine
* Copy the file ```.emacs``` to your home directory: 
   * ```cd resources```
   * ```git pull```
   * ```cp .emacs ~/```
   * ```cp -R .emacs.d ~/```

# .Emacs file with more detail

What you're doing with the above is copying a personalization file to your 
home directory. Every time emacs starts up, it looks at ```~/.emacs``` to see if 
there is a file there, and if so, runs it. 

The ```.emacs``` file is a list of commands that, when run in emacs, change preferences. 

The ```.emacs``` file I provided for you is below: 

```
(global-linum-mode t)
(global-whitespace-mode t)
;; (add-hook 'c-mode-common-hook '(lambda () (c-toggle-auto-state 1)))
(require 'cc-mode)
(defun my-indent-setup ()
  (c-set-offset 'arglist-intro '+))
(add-hook 'java-mode-hook 'my-indent-setup)
(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(custom-enabled-themes (quote (tango-dark)))
 '(inhibit-startup-screen t))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:family "DejaVu Sans Mono" :foundry "PfEd" :slant normal :weight bold :height 120 :width normal)))))
(add-to-list 'load-path "~/.emacs.d/lisp/") 
(require 'google-c-style)
(add-hook 'c-mode-common-hook 'google-set-c-style)
(add-hook 'c-mode-common-hook 'google-make-newline-indent)
```

It looks a little funny because emacs is written in Lisp, which starts a command with an open paren, then the function name, then the parameters. 

The first line here turns on line numbers every time emacs starts up. 

The second line shows whitespace in all buffers. 

The line that starts with ```(custom-enabled-themes...``` says I like a dark theme. 

The next line says I don't want to see the startup screen every time emacs starts. 

The ```(custom-set-faces``` line gives me a font I like better than the default. 

The last few lines add a customization that implements Google's C Style whitespace rules. This way, 
it highlights when I have whitespace that is not consistent with Google's C Style whitespace guidelines. 

