/***************************************************************************
* ALPS++ library
*
* parser/parser.h   a simple parser 
*
* $Id$
*
* Copyright (C) 2001-2003 by Matthias Troyer <troyer@itp.phys.ethz.ch>,
*                            Synge Todo <wistaria@comp-phys.org>,
*
* Permission is hereby granted, free of charge, to any person or organization 
* obtaining a copy of the software covered by this license (the "Software") 
* to use, reproduce, display, distribute, execute, and transmit the Software, 
* and to prepare derivative works of the Software, and to permit others
* to do so for non-commerical academic use, all subject to the following:
*
* The copyright notice in the Software and this entire statement, including 
* the above license grant, this restriction and the following disclaimer, 
* must be included in all copies of the Software, in whole or in part, and 
* all derivative works of the Software, unless such copies or derivative 
* works are solely in the form of machine-executable object code generated by 
* a source language processor.

* In any scientific publication based in part or wholly on the Software, the
* use of the Software has to be acknowledged and the publications quoted
* on the web page http://www.alps.org/license/ have to be referenced.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT 
* SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE 
* FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE, 
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
* DEALINGS IN THE SOFTWARE.
*
**************************************************************************/

#ifndef ALPS_PARSER_PARSER_H
#define ALPS_PARSER_PARSER_H

#include <alps/cctype.h>
#include <map>
#include <string>

namespace alps {

namespace detail {

inline bool is_identifier_char(char c) 
{ 
  return std::isalnum(c) || c=='_' || c=='\'' || c==':';
}

} // end namespace detail

extern std::string parse_identifier(std::istream& in);

extern std::string read_until(std::istream& in, char end);

extern void check_character(std::istream& in, char c, const std::string& err);

struct XMLTag
{
  XMLTag() {}
  typedef std::map<std::string,std::string> AttributeMap;
  std::string name;
  AttributeMap attributes;
  enum {OPENING, CLOSING, SINGLE, COMMENT, PROCESSING} type;
  bool is_comment() { return type==COMMENT;}
  bool is_processing() { return type==PROCESSING;}
  bool is_element() { return !is_comment() && !is_processing();}
};

XMLTag parse_tag(std::istream& p, bool skip_comments = false);

std::string parse_content(std::istream& in);

void skip_element(std::istream& in,const XMLTag&);

void check_tag(std::istream& in, const std::string& name);

} // end namespace alps

#endif // PALM_PARSER_PARSER_H
