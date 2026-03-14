/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakibar <hakibar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 18:53:41 by hakibar           #+#    #+#             */
/*   Updated: 2026/03/13 18:53:42 by hakibar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

static std::string	replaceAll(const std::string &content,
	const std::string &s1, const std::string &s2)
{
	std::string	result;
	size_t		pos;
	size_t		found;

	pos = 0;
	found = content.find(s1, pos);
	while (found != std::string::npos)
	{
		result.append(content, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
		found = content.find(s1, pos);
	}
	result.append(content, pos, content.length() - pos);
	return (result);
}

int	main(int argc, char **argv)
{
	std::ifstream	inputFile;
	std::ofstream	outputFile;
	std::ostringstream	buffer;
	std::string		content;
	std::string		replaced;
	std::string		outputName;

	if (argc != 4)
	{
		std::cerr << "Usage: ./sedIsForLosers <filename> <s1> <s2>" << '\n';
		return (1);
	}
	if (std::string(argv[2]).empty())
	{
		std::cerr << "Error: s1 cannot be empty." << '\n';
		return (1);
	}
	inputFile.open(argv[1]);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: cannot open input file." << '\n';
		return (1);
	}
	buffer << inputFile.rdbuf();
	content = buffer.str();
	inputFile.close();
	replaced = replaceAll(content, argv[2], argv[3]);
	outputName = std::string(argv[1]) + ".replace";
	outputFile.open(outputName.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: cannot create output file." << '\n';
		return (1);
	}
	outputFile << replaced;
	outputFile.close();
	return (0);
}
