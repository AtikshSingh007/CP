<h2><a href="https://codeforces.com/contest/1715/problem/C" target="_blank" rel="noopener noreferrer">1715C — Monoblock</a></h2>

| | |
|---|---|
| **Difficulty** | 1700 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1715C](https://codeforces.com/contest/1715/problem/C) |

## Topics
`combinatorics` `data structures` `implementation` `math`

---

## Problem Statement

<div class="header"><div class="title">C. Monoblock</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Stanley has decided to buy a new desktop PC made by the company "Monoblock", and to solve captcha on their website, he needs to solve the following task.</p><p>The <span class="tex-font-style-it">awesomeness</span> of an array is the minimum number of blocks of consecutive identical numbers in which the array could be split. For example, the awesomeness of an array </p><ul> <li> $$$[1, 1, 1]$$$ is $$$1$$$; </li><li> $$$[5, 7]$$$ is $$$2$$$, as it could be split into blocks $$$[5]$$$ and $$$[7]$$$; </li><li> $$$[1, 7, 7, 7, 7, 7, 7, 7, 9, 9, 9, 9, 9, 9, 9, 9, 9]$$$ is 3, as it could be split into blocks $$$[1]$$$, $$$[7, 7, 7, 7, 7, 7, 7]$$$, and $$$[9, 9, 9, 9, 9, 9, 9, 9, 9]$$$. </li></ul><p>You are given an array $$$a$$$ of length $$$n$$$. There are $$$m$$$ queries of two integers $$$i$$$, $$$x$$$. A query $$$i$$$, $$$x$$$ means that from now on the $$$i$$$-th element of the array $$$a$$$ is equal to $$$x$$$.</p><p>After each query print the sum of awesomeness values among all subsegments of array $$$a$$$. In other words, after each query you need to calculate $$$$$$\sum\limits_{l = 1}^n \sum\limits_{r = l}^n g(l, r),$$$$$$ where $$$g(l, r)$$$ is the awesomeness of the array $$$b = [a_l, a_{l + 1}, \ldots, a_r]$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>In the first line you are given with two integers $$$n$$$ and $$$m$$$ ($$$1 \leq n, m \leq 10^5$$$).</p><p>The second line contains $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$1 \le a_i \le 10^9$$$) — the array $$$a$$$.</p><p>In the next $$$m$$$ lines you are given the descriptions of queries. Each line contains two integers $$$i$$$ and $$$x$$$ ($$$1 \leq i \leq n$$$, $$$1 \leq x \leq 10^9$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print the answer to each query on a new line.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005729176180627361" id="id007208771743120851" class="input-output-copier">Copy</div></div><pre id="id005729176180627361">5 5
1 2 3 4 5
3 2
4 2
3 1
2 1
2 2
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id003381479985577509" id="id005233519391527777" class="input-output-copier">Copy</div></div><pre id="id003381479985577509">29
23
35
25
35
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>After the first query $$$a$$$ is equal to $$$[1, 2, 2, 4, 5]$$$, and the answer is $$$29$$$ because we can split each of the subsegments the following way: </p><ol> <li> $$$[1; 1]$$$: $$$[1]$$$, 1 block; </li><li> $$$[1; 2]$$$: $$$[1] + [2]$$$, 2 blocks; </li><li> $$$[1; 3]$$$: $$$[1] + [2, 2]$$$, 2 blocks; </li><li> $$$[1; 4]$$$: $$$[1] + [2, 2] + [4]$$$, 3 blocks; </li><li> $$$[1; 5]$$$: $$$[1] + [2, 2] + [4] + [5]$$$, 4 blocks; </li><li> $$$[2; 2]$$$: $$$[2]$$$, 1 block; </li><li> $$$[2; 3]$$$: $$$[2, 2]$$$, 1 block; </li><li> $$$[2; 4]$$$: $$$[2, 2] + [4]$$$, 2 blocks; </li><li> $$$[2; 5]$$$: $$$[2, 2] + [4] + [5]$$$, 3 blocks; </li><li> $$$[3; 3]$$$: $$$[2]$$$, 1 block; </li><li> $$$[3; 4]$$$: $$$[2] + [4]$$$, 2 blocks; </li><li> $$$[3; 5]$$$: $$$[2] + [4] + [5]$$$, 3 blocks; </li><li> $$$[4; 4]$$$: $$$[4]$$$, 1 block; </li><li> $$$[4; 5]$$$: $$$[4] + [5]$$$, 2 blocks; </li><li> $$$[5; 5]$$$: $$$[5]$$$, 1 block; </li></ol> which is $$$1 + 2 + 2 + 3 + 4 + 1 + 1 + 2 + 3 + 1 + 2 + 3 + 1 + 2 + 1 = 29$$$ in total.</div>