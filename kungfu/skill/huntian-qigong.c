// huntian-qigong.c

// written by Xiang



inherit FORCE;
inherit F_DBASE;
public string query_type() {
       return "yang";
}



int valid_enable(string usage) 

{ 

   return usage == "force"; 

}



/*

int valid_learn()

// need more limit here

{

	return 1;

}

*/



int practice_skill(object me)

{

	return notify_fail("混天气功只能用学(learn)的来增加熟练度。\n");

}



string exert_function_file(string func)

{

	return SKILL_D("huntian-qigong/") + func;

}



