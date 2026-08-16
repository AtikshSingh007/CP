<h2><a href="https://codeforces.com/contest/1598/problem/D" target="_blank" rel="noopener noreferrer">1598D — Training Session</a></h2>

| | |
|---|---|
| **Difficulty** | 1700 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1598D](https://codeforces.com/contest/1598/problem/D) |

## Topics
`combinatorics` `data structures` `geometry` `implementation` `math`

---

## Problem Statement

<div class="header"><div class="title">D. Training Session</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Monocarp is the coach of the Berland State University programming teams. He decided to compose a problemset for a training session for his teams.</p><p>Monocarp has $$$n$$$ problems that none of his students have seen yet. The $$$i$$$-th problem has a topic $$$a_i$$$ (an integer from $$$1$$$ to $$$n$$$) and a difficulty $$$b_i$$$ (an integer from $$$1$$$ to $$$n$$$). All problems are different, that is, there are no two tasks that have the same topic and difficulty at the same time.</p><p>Monocarp decided to select exactly $$$3$$$ problems from $$$n$$$ problems for the problemset. The problems should satisfy <span class="tex-font-style-bf">at least one</span> of two conditions (possibly, both):</p><ul> <li> the topics of all three selected problems are different; </li><li> the difficulties of all three selected problems are different. </li></ul><p>Your task is to determine the number of ways to select three problems for the problemset.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains a single integer $$$t$$$ ($$$1 \le t \le 50000$$$) — the number of testcases.</p><p>The first line of each testcase contains an integer $$$n$$$ ($$$3 \le n \le 2 \cdot 10^5$$$) — the number of problems that Monocarp have.</p><p>In the $$$i$$$-th of the following $$$n$$$ lines, there are two integers $$$a_i$$$ and $$$b_i$$$ ($$$1 \le a_i, b_i \le n$$$) — the topic and the difficulty of the $$$i$$$-th problem.</p><p>It is guaranteed that there are no two problems that have the same topic and difficulty at the same time.</p><p>The sum of $$$n$$$ over all testcases doesn't exceed $$$2 \cdot 10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print the number of ways to select three training problems that meet either of the requirements described in the statement.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id009778347339139304" id="id006282640558105483" class="input-output-copier">Copy</div></div><pre id="id009778347339139304">2
4
2 4
3 4
2 1
1 3
5
1 5
2 4
3 3
4 2
5 1
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0037853587168554215" id="id006231570718629721" class="input-output-copier">Copy</div></div><pre id="id0037853587168554215">3
10
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first example, you can take the following sets of three problems:</p><ul> <li> problems $$$1$$$, $$$2$$$, $$$4$$$; </li><li> problems $$$1$$$, $$$3$$$, $$$4$$$; </li><li> problems $$$2$$$, $$$3$$$, $$$4$$$. </li></ul><p>Thus, the number of ways is equal to three.</p></div>