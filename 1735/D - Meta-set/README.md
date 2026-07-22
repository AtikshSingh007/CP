<h2><a href="https://codeforces.com/contest/1735/problem/D" target="_blank" rel="noopener noreferrer">1735D — Meta-set</a></h2>

| | |
|---|---|
| **Difficulty** | 1700 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1735D](https://codeforces.com/contest/1735/problem/D) |

## Topics
`brute force` `combinatorics` `data structures` `hashing` `math`

---

## Problem Statement

<div class="header"><div class="title">D. Meta-set</div><div class="time-limit"><div class="property-title">time limit per test</div>4 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You like the card board game "Set". Each card contains $$$k$$$ features, each of which is equal to a value from the set $$$\{0, 1, 2\}$$$. The deck contains all possible variants of cards, that is, there are $$$3^k$$$ different cards in total.</p><p>A feature for three cards is called <span class="tex-font-style-it">good</span> if it is the same for these cards or pairwise distinct. Three cards are called a <span class="tex-font-style-it">set</span> if all $$$k$$$ features are good for them.</p><p>For example, the cards $$$(0, 0, 0)$$$, $$$(0, 2, 1)$$$, and $$$(0, 1, 2)$$$ form a set, but the cards $$$(0, 2, 2)$$$, $$$(2, 1, 2)$$$, and $$$(1, 2, 0)$$$ do not, as, for example, the last feature is not good.</p><p>A group of <span class="tex-font-style-bf">five</span> cards is called a <span class="tex-font-style-it">meta-set</span>, if there is strictly more than one set among them. How many meta-sets there are among given $$$n$$$ distinct cards?</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line of the input contains two integers $$$n$$$ and $$$k$$$ ($$$1 \le n \le 10^3$$$, $$$1 \le k \le 20$$$) — the number of cards on a table and the number of card features. The description of the cards follows in the next $$$n$$$ lines.</p><p>Each line describing a card contains $$$k$$$ integers $$$c_{i, 1}, c_{i, 2}, \ldots, c_{i, k}$$$ ($$$0 \le c_{i, j} \le 2$$$) — card features. It is guaranteed that all cards are distinct.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Output one integer — the number of meta-sets.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0006338760899862383" id="id006111922504700487" class="input-output-copier">Copy</div></div><pre id="id0006338760899862383">8 4
0 0 0 0
0 0 0 1
0 0 0 2
0 0 1 0
0 0 2 0
0 1 0 0
1 0 0 0
2 2 0 0
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id004777183398290018" id="id006311325467955681" class="input-output-copier">Copy</div></div><pre id="id004777183398290018">1
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0003271349089074349" id="id009319935546981801" class="input-output-copier">Copy</div></div><pre id="id0003271349089074349">7 4
0 0 0 0
0 0 0 1
0 0 0 2
0 0 1 0
0 0 2 0
0 1 0 0
0 2 0 0
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id005606275590622896" id="id009692138869264616" class="input-output-copier">Copy</div></div><pre id="id005606275590622896">3
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005201120650996075" id="id009517334434443255" class="input-output-copier">Copy</div></div><pre id="id005201120650996075">9 2
0 0
0 1
0 2
1 0
1 1
1 2
2 0
2 1
2 2
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0016126642544502467" id="id00861692687365926" class="input-output-copier">Copy</div></div><pre id="id0016126642544502467">54
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id009060786801736037" id="id00936120239508937" class="input-output-copier">Copy</div></div><pre id="id009060786801736037">20 4
0 2 0 0
0 2 2 2
0 2 2 1
0 2 0 1
1 2 2 0
1 2 1 0
1 2 2 1
1 2 0 1
1 1 2 2
1 1 0 2
1 1 2 1
1 1 1 1
2 1 2 0
2 1 1 2
2 1 2 1
2 1 1 1
0 1 1 2
0 0 1 0
2 2 0 0
2 0 0 2
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0005167701937072289" id="id007675338107163137" class="input-output-copier">Copy</div></div><pre id="id0005167701937072289">0
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>Let's draw the cards indicating the first four features. The first feature will indicate the number of objects on a card: $$$1$$$, $$$2$$$, $$$3$$$. The second one is the color: red, green, purple. The third is the shape: oval, diamond, squiggle. The fourth is filling: open, striped, solid.</p><p>You can see the first three tests below. For the first two tests, the meta-sets are highlighted.</p><p>In the first test, the only meta-set is the five cards $$$(0000,\ 0001,\ 0002,\ 0010,\ 0020)$$$. The sets in it are the triples $$$(0000,\ 0001,\ 0002)$$$ and $$$(0000,\ 0010,\ 0020)$$$. Also, a set is the triple $$$(0100,\ 1000,\ 2200)$$$ which does not belong to any meta-set. </p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/294b433719e5c7d42bd7eaa11a549d189bd488de.png" style="max-width: 100.0%;max-height: 100.0%;" width="832px"> </center><p>In the second test, the following groups of five cards are meta-sets: $$$(0000,\ 0001,\ 0002,\ 0010,\ 0020)$$$, $$$(0000,\ 0001,\ 0002,\ 0100,\ 0200)$$$, $$$(0000,\ 0010,\ 0020,\ 0100,\ 0200)$$$. </p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/37ff40acf802ba24393cecf877ecbea33f89397b.png" style="max-width: 100.0%;max-height: 100.0%;" width="832px"> </center><p>In there third test, there are $$$54$$$ meta-sets. </p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/880c85c827f3a1b11ccab331703ef4ea25a39db6.png" style="max-width: 100.0%;max-height: 100.0%;" width="832px"> </center></div>