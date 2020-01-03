import subprocess
import unittest
import sys
import os
from os.path import dirname, abspath


class TestMinishell(unittest.TestCase):
	# context = os.path.split(os.path.dirname(__file__))[0]
	context = d = dirname(dirname(abspath(__file__)))
	minishell = "%s/minishell" % context

	def execute_my_shell(self, command):
		cmd_list = ["/bin/echo"] + command
		p_command = subprocess.Popen(cmd_list, stdout=subprocess.PIPE)

		p_minishell = subprocess.Popen(
			[self.minishell],
			stdin=p_command.stdout,
			stdout=subprocess.PIPE,
			stderr=subprocess.PIPE)
		p_command.stdout.close()
		stdout, stderr = p_minishell.communicate()
		return stdout.decode(), stderr.decode()

	def execute_real_shell(self, command):
		cmd_list = ["/bin/echo"] + command
		p_command = subprocess.Popen(cmd_list, stdout=subprocess.PIPE)
		p_real_shell = subprocess.Popen(
			["/bin/bash"],
			stdin=p_command.stdout,
			stdout=subprocess.PIPE,
			stderr=subprocess.PIPE)
		p_command.stdout.close()
		stdout, stderr = p_real_shell.communicate()
		return stdout.decode(), stderr.decode()

	def compare_shells(self, command):
		real_std = self.execute_real_shell(command)
		my_std = self.execute_my_shell(command)
		self.assertEqual(real_std, my_std)

	def test_echo(self):
		command = ["echo", "one", "two"]
		self.compare_shells(command)

if __name__ == '__main__':
	unittest.main()