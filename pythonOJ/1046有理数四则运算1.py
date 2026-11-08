import fractions as f
s=input()
s=f.Fraction(s)
t=input()
t=f.Fraction(t)
sum=s+t
print(f"{sum.numerator}/{sum.denominator}")
