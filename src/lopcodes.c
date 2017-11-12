/*
** $Id: lopcodes.c,v 1.37.1.1 2007/12/27 13:02:25 roberto Exp $
** See Copyright Notice in lua.h
*/


#define lopcodes_c
#define LUA_CORE


#include "lopcodes.h"


/* ORDER OP */

const char *const luaP_opnames[NUM_OPCODES+1] = {
  "LOADNIL",
  "SUB",
  "UNM",
  "CLOSURE",
  "TESTSET",
  "NEWTABLE",
  "LEN",
  "LE",
  "SETLIST",
  "LOADBOOL",
  "FORPREP",
  "DIV",
  "RETURN",
  "MOD",
  "FORLOOP",
  "SETTABLE",
  "TEST",
  "LT",
  "TAILCALL",
  "LOADK",
  "GETTABLE",
  "CALL",
  "GETUPVAL",
  "POW",
  "TFORLOOP",
  "MOVE",
  "SETGLOBAL",
  "SELF",
  "GETGLOBAL",
  "MUL",
  "SETUPVAL",
  "NOT",
  "CLOSE",
  "ADD",
  "CONCAT",
  "JMP",
  "EQ",
  "VARARG",
  NULL
};


#define opmode(t,a,b,c,m) (((t)<<7) | ((a)<<6) | ((b)<<4) | ((c)<<2) | (m))

const lu_byte luaP_opmodes[NUM_OPCODES] = {
/*       T  A    B       C     mode		   opcode	*/
opmode(0, 1, OpArgR, OpArgN, iABC)
,opmode(0, 1, OpArgK, OpArgK, iABC)
,opmode(0, 1, OpArgR, OpArgN, iABC)
,opmode(0, 1, OpArgU, OpArgN, iABx)
,opmode(1, 1, OpArgR, OpArgU, iABC)
,opmode(0, 1, OpArgU, OpArgU, iABC)
,opmode(0, 1, OpArgR, OpArgN, iABC)
,opmode(1, 0, OpArgK, OpArgK, iABC)
,opmode(0, 0, OpArgU, OpArgU, iABC)
,opmode(0, 1, OpArgU, OpArgU, iABC)
,opmode(0, 1, OpArgR, OpArgN, iAsBx)
,opmode(0, 1, OpArgK, OpArgK, iABC)
,opmode(0, 0, OpArgU, OpArgN, iABC)
,opmode(0, 1, OpArgK, OpArgK, iABC)
,opmode(0, 1, OpArgR, OpArgN, iAsBx)
,opmode(0, 0, OpArgK, OpArgK, iABC)
,opmode(1, 1, OpArgR, OpArgU, iABC)
,opmode(1, 0, OpArgK, OpArgK, iABC)
,opmode(0, 1, OpArgU, OpArgU, iABC)
,opmode(0, 1, OpArgK, OpArgN, iABx)
,opmode(0, 1, OpArgR, OpArgK, iABC)
,opmode(0, 1, OpArgU, OpArgU, iABC)
,opmode(0, 1, OpArgU, OpArgN, iABC)
,opmode(0, 1, OpArgK, OpArgK, iABC)
,opmode(1, 0, OpArgN, OpArgU, iABC)
,opmode(0, 1, OpArgR, OpArgN, iABC) 
,opmode(0, 0, OpArgK, OpArgN, iABx)
,opmode(0, 1, OpArgR, OpArgK, iABC)
,opmode(0, 1, OpArgK, OpArgN, iABx)
,opmode(0, 1, OpArgK, OpArgK, iABC)
,opmode(0, 0, OpArgU, OpArgN, iABC)
,opmode(0, 1, OpArgR, OpArgN, iABC)
,opmode(0, 0, OpArgN, OpArgN, iABC)
,opmode(0, 1, OpArgK, OpArgK, iABC)
,opmode(0, 1, OpArgR, OpArgR, iABC)
,opmode(0, 0, OpArgR, OpArgN, iAsBx)
,opmode(1, 0, OpArgK, OpArgK, iABC)
,opmode(0, 1, OpArgU, OpArgN, iABC)

};

