'''
'/home/foo'
'/home/bar'
'/home/baz/one'
'/home/baz/two'
'''

class NodeType:
	REGULAR = 1
	FILE = 2
	DIRECTORY = 3

class Node(object):
	def __init__(self, c, t):
		self.char = c
		self.type = t
		self.children = {}

class PathParser(object):
	def __init__(self):
		self.root = Node('', NodeType.DIRECTORY)
		
	def add_path(self, abs_path):
		if abs_path[0] is not '/':
			print 'ERROR: path should start with slash!'
			return

		parent_node = self.root
		i = 1
		while i < len(abs_path) - 1:
			if abs_path[i] == '/':
				i += 1
				continue

			if abs_path[i] not in parent_node.children:
				current_node = Node(abs_path[i], NodeType.DIRECTORY if abs_path[i + 1] == '/' else NodeType.REGULAR)
				parent_node.children[abs_path[i]] = current_node

	 		parent_node = parent_node.children[abs_path[i]]
	 		i += 1

	 	if abs_path[i] not in parent_node.children:
	 		current_node = Node(abs_path[i], NodeType.FILE)
	 		parent_node.children[abs_path[i]] = current_node

	def print_path(self, path, node):
		if node.type is NodeType.FILE:
			print path + node.char

		for child in node.children:
			self.print_path(path + node.char + ('/' if node.type is NodeType.DIRECTORY else ''), node.children[child])

	def print_all_paths(self):
		self.print_path('', self.root)

	def print_pattern(self, node):
		children_pattern = ''
		if len(node.children) == 1:
			children_pattern = self.print_pattern(node.children.values()[0])
		elif len(node.children) > 1:
			tmp = []
			for child in node.children.values():
				tmp.append(self.print_pattern(child))
			children_pattern = '{' + ','.join(sorted(tmp)) + '}'

		return node.char + ('/' if node.type is NodeType.DIRECTORY else '') + children_pattern


path_parser = PathParser()
path_parser.add_path('/home/foo')
path_parser.add_path('/home/bar')
path_parser.add_path('/home/baz/one')
path_parser.add_path('/home/baz/two')
path_parser.print_all_paths()
print path_parser.print_pattern(path_parser.root)
