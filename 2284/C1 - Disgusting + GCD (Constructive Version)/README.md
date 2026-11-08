<h2><a href="https://codeforces.com/contest/2284/problem/C1" target="_blank" rel="noopener noreferrer">2284C1 — Disgusting + GCD (Constructive Version)</a></h2>

| | |
|---|---|
| **Difficulty** | Unrated |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2284C1](https://codeforces.com/contest/2284/problem/C1) |

## Topics
`constructive algorithms` `dp` `graphs` `greedy` `math` `number theory`

---

## Problem Statement

<div class="header"><div class="title">C1. Disgusting + GCD (Constructive Version)</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>  </p><p><span class="tex-font-style-bf">This is the constructive version of the problem.</span></p><p>In this version, you are kijjot.</p><p>An array $$$b$$$ is called <span class="tex-font-style-it">disgusting</span> if there exist indices $$$i  \lt  j$$$ such that $$$1  \lt  \gcd(b_i, b_j)  \lt  \min(b_i, b_j)$$$$$$^{\text{∗}}$$$.</p><p>You are given an array $$$a$$$ of length $$$n$$$, consisting of positive integers. To prevent eternal merging, you need to make it <span class="tex-font-style-bf">not</span> <span class="tex-font-style-it">disgusting</span>.</p><p>To do this, you can perform the following operation: choose an index $$$1 \le i \le n$$$ and a positive integer $$$1 \le x \le 10^9$$$ such that $$$\gcd(a_i, x) = 1$$$, and increase $$$a_i$$$ by $$$x$$$. Note that the condition is checked using the <span class="tex-font-style-bf">current</span> value of $$$a_i$$$ before the operation, not its value in the original array.</p><p>Your strength is running low, so you can perform operations subject to the following restrictions: </p><ul> <li> You can perform at most $$$n + 10$$$ operations. </li><li> The sum of the values of $$$x$$$ over all performed operations must not exceed the sum of the elements of the <span class="tex-font-style-bf">original</span> array $$$a$$$. </li></ul><p>Find any valid array obtained as a result of applying the operations. It can be shown that under the given constraints, such an array always exists.</p><div class="statement-footnote"><p>$$$^{\text{∗}}$$$$$$\gcd(x, y)$$$ denotes the <a href="https://en.wikipedia.org/wiki/Greatest_common_divisor">greatest common divisor (GCD)</a> of integers $$$x$$$ and $$$y$$$.</p></div></div><div class="input-specification"><div class="section-title">Input</div><p>Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 10^4$$$). The description of the test cases follows.</p><p>The first line of each test case contains a single integer $$$n$$$ ($$$2 \le n \le 10^5$$$) — the length of the array.</p><p>The second line contains $$$n$$$ integers $$$a_1, a_2, \ldots, a_n$$$ ($$$2 \le a_i \le 10^5$$$) — the elements of the array.</p><p>It is guaranteed that the sum of $$$n$$$ over all test cases does not exceed $$$10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output $$$n$$$ integers $$$b_1, b_2, \ldots, b_n$$$ ($$$a_i \le b_i \le 10^9$$$) — the array $$$b$$$ resulting from the operations.</p><p>The array $$$b$$$ must not be <span class="tex-font-style-it">disgusting</span> and must be obtainable from $$$a$$$ using the allowed operations while satisfying both restrictions. If there are multiple valid arrays, output any of them.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id008995297700157167" id="id003495140991364595" class="input-output-copier">Copy</div></div><pre id="id008995297700157167">3
2
7 12
3
7 9 12
7
8 76 49 26 24 80 99
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0007493551436364243" id="id00948492072154016" class="input-output-copier">Copy</div></div><pre id="id0007493551436364243">7 12
7 25 12
9 77 50 27 25 81 100
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first example, we can perform no operations, since the array is already not <span class="tex-font-style-it">disgusting</span>.</p><p>In the second example, the array is <span class="tex-font-style-it">disgusting</span> because $$$1  \lt  \gcd(a_2, a_3) = \gcd(9, 12) = 3  \lt  \min(a_2, a_3) = \min(9, 12) = 9$$$ holds. We can choose $$$i=2$$$ and $$$x=16$$$, since $$$\gcd(x, a_i) = \gcd(16, 9) = 1$$$. After this, the array $$$a$$$ will become equal to $$$[7, 25, 12]$$$ and will no longer be <span class="tex-font-style-it">disgusting</span>.</p></div>