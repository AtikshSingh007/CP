<h2><a href="https://codeforces.com/contest/1557/problem/C" target="_blank" rel="noopener noreferrer">1557C — Moamen and XOR</a></h2>

| | |
|---|---|
| **Difficulty** | 1700 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1557C](https://codeforces.com/contest/1557/problem/C) |

## Topics
`bitmasks` `combinatorics` `dp` `math` `matrices`

---

## Problem Statement

<div class="header"><div class="title">C. Moamen and XOR</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Moamen and Ezzat are playing a game. They create an array $$$a$$$ of $$$n$$$ non-negative integers where every element is less than $$$2^k$$$.</p><p>Moamen wins if $$$a_1 \,\&\, a_2 \,\&\, a_3 \,\&\, \ldots \,\&\, a_n \ge a_1 \oplus a_2 \oplus a_3 \oplus \ldots \oplus a_n$$$.</p><p>Here $$$\&$$$ denotes the <a href="https://en.wikipedia.org/wiki/Bitwise_operation#AND">bitwise AND operation</a>, and $$$\oplus$$$ denotes the <a href="https://en.wikipedia.org/wiki/Bitwise_operation#XOR">bitwise XOR operation</a>.</p><p>Please calculate the number of winning for Moamen arrays $$$a$$$.</p><p>As the result may be very large, print the value modulo $$$1\,000\,000\,007$$$ ($$$10^9 + 7$$$).</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains a single integer $$$t$$$ ($$$1 \le t \le 5$$$)— the number of test cases. </p><p>Each test case consists of one line containing two integers $$$n$$$ and $$$k$$$ ($$$1 \le n\le 2\cdot 10^5$$$, $$$0 \le k \le 2\cdot 10^5$$$).</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, print a single value — the number of different arrays that Moamen wins with.</p><p>Print the result modulo $$$1\,000\,000\,007$$$ ($$$10^9 + 7$$$).</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0013396967562267348" id="id007229693855176371" class="input-output-copier">Copy</div></div><pre id="id0013396967562267348">3
3 1
2 1
4 0
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009343684791048522" id="id0048225913006775056" class="input-output-copier">Copy</div></div><pre id="id009343684791048522">5
2
1
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first example, $$$n = 3$$$, $$$k = 1$$$. As a result, all the possible arrays are $$$[0,0,0]$$$, $$$[0,0,1]$$$, $$$[0,1,0]$$$, $$$[1,0,0]$$$, $$$[1,1,0]$$$, $$$[0,1,1]$$$, $$$[1,0,1]$$$, and $$$[1,1,1]$$$.</p><p>Moamen wins in only $$$5$$$ of them: $$$[0,0,0]$$$, $$$[1,1,0]$$$, $$$[0,1,1]$$$, $$$[1,0,1]$$$, and $$$[1,1,1]$$$.</p></div>