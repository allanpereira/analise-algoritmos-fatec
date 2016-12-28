Source: [https://justin.abrah.ms/computer-science/how-to-calculate-big-o.html](https://justin.abrah.ms/computer-science/how-to-calculate-big-o.html)

# Big-O is easy to calculate, if you know how

## Calculating Big-O

So now that we [know what Big-O is](https://justin.abrah.ms/computer-science/big-o-notation-explained.html), how do we calculate the Big-O classification of a given function? It's just as easy as following along with your code and counting along the way.

```python
def count_ones(a_list):
    total = 0
    for element in a_list:
        if element == 1:
            total += 1
    return total
```
      
The above code is a classic example of an `O(n)` function. This is because we have to loop over every element that we get in order to complete our calculation. We can trace this by following along the code and counting. We're doing a few calculations here.

  1. We're setting total to zero.
  2. We loop through a_list.
  3. We check if element is equal to 1.
  4. We increment total by one a few times.

So setting a counter to zero is a constant time operation. If you think about what's happening inside the computer, we're setting a chunk of memory to some new value. Because we've hard-coded the zero here, it happens in constant time. There's no way to call this function or alter global state that we could change the operation. This is an `O(1)` operation.

Next, we loop through the list. So we have to look at each item in the list. This number of operations changes depending on the size of the list. If it's a list of 10 things, we do it 10 times. If it's 75, we do 75 operations. In mathematical terms, this means that the time it takes to do something increases linearly with its input. We use a variable to represent the size of the input, which everyone in the industry calls `n`. So the "loop over the list" function is `O(n)` where `n` represents the size of `a_list`.

Checking whether an element is equal to 1 is an `O(1)` operation. A way to prove to ourselves that this is true is to think about it as a function. If we had an `is_equal_to_one()` function, would it take longer if you passed in more values (eg `is_equal_to_one(4)` vs `is_equal_to_one([1,2,3,4,5])`? It wouldn't because of the fixed number 1 in our comparison. It took me a while of conferring with other people about why this was true before I was convinced. We decided that binary comparisons are constant time and that's what a comparison to 1 eventually got to.

Next, we increment total by 1. This is like setting total to zero (but you have to do addition first). Addition of one, like equality, is also constant time.

So where are we? We have \(O(1) + O(n) * (O(1) + O(1))\). This is because we do 1 up front, constant time operation, then (potentially) 2 more constant item things for each item in the list. In math terms, that reduces to \(O(2n) + O(1)\). In big O, we only care about the biggest "term" here. "Term" is the mathematical word that means "portion of an algebraic statement".

To figure out the biggest expression if you don't remember the order, you can just cheat and graph them. From the other article, [we know](https://justin.abrah.ms/computer-science/big-o-notation-explained.html) that to graph these things you just replace `n` with `x`.

![Graph](https://justin.abrah.ms/static/images/2n_vs_1__plot.png "Graph")


So as I was saying, in calculating Big-O, we're only interested in the biggest term: `O(2n)`. Because Big-O only deals in approximation, we drop the 2 entirely, because the difference between `2n` and `n` isn't fundamentally different. The growth is still linear, it's just a faster growing linear function. You drop the products of (aka things multiplying) the variables. This is because these change the rate of growth, but not the type of growth. If you want a visual indication of this, compare the graph of `x^2` vs `2x` vs `x`. `x^2` is a different type of growth from the other two (quadratic [which is just a math-y way of saying "squared"] vs linear), just like `2n` is a different type of growth from `1` in the graph above (linear vs constant). Even if you pick a really high multiplier like 10,000, we can still beat it with `x^2` because eventually the line for `x^2` will be higher if we go far enough to the right.

To sum it up, the answer is this function has an `O(N)` runtime (or a linear runtime). It runs slower the more things you give it, but that should grow at a predictable rate.

The key aspects to determining the Big-O of a function is really just as simple as counting. Enumerate the different operations your code does (be careful to understand what happens when you call out into another function!), then determine how they relate to your inputs. From there, its just simplifying to the biggest term and dropping the multipliers.

If you found this interesting, I'm thinking about writing up a longer form book on this topic. Head over to [leanpub](https://leanpub.com/computer-science-for-self-taught-programmers) and express your interest in hearing more. If you have any questions, please feel free to [email me](mailto:justin+how-to-calculate-big-o@abrah.ms).

Thanks to [Wraithan](https://twitter.com/wraithan), [Chris Dickinson](https://twitter.com/isntitvacant) and [Cory Kolbeck](https://twitter.com/cbeckpdx) for their review.