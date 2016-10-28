def simplify(path):
    places = [p for p in path.split("/") if p!="." and p!=""]
    stack = []
    for p in places:
        if p == "..":
            if len(stack) > 0:
                stack.pop()
        else:
            stack.append(p)
    return "/" + "/".join(stack)


print(simplify('./'))
print(simplify('./folder1//folder2/../folder3'))
print(simplify('./folder1//./.././/../../..'))
print(simplify('//'))
print(simplify(""))
# print(simplify(None))