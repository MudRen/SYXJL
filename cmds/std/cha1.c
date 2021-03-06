// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "初学乍练" NOR,
        HIB "粗通皮毛" NOR,
        HIB "半生不熟" NOR,
        HIB "马马虎虎" NOR,
        HIB "驾轻就熟" NOR,
        CYN "出类拔萃" NOR,
        CYN "神乎其技" NOR,
        CYN "出神入化" NOR,
        HIC "登峰造极" NOR,
        HIC "一代宗师" NOR,
        HIW "深不可测" NOR
});

string *knowledge_level_desc = ({
        BLU "新学乍会" NOR,
        HIB "初窥门径" NOR,
        HIB "略知一二" NOR,
        HIB "马马虎虎" NOR,
        HIB "已有小成" NOR,
        CYN "心领神会" NOR,
        CYN "了然於胸" NOR,
        CYN "豁然贯通" NOR,
        HIC "举世无双" NOR,
        HIC "震古铄今" NOR,
        HIW "深不可测" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
        object ob;
        mapping skill_learn,skill_practice, skill_learned,skill_practiced,map;
        string *sname, *sname_p, *mapped;
        int i;

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob || !me->visible(ob)) return notify_fail("你要察看谁的技能？\n");
        }

        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) )
                return notify_fail("只有巫师或有师徒关系的人能察看他人的技能。\n");

        skill_learn = ob->query_learn_skills();
        skill_practice = ob->query_practice_skills();
        if(!sizeof(skill_learn)&&!sizeof(skill_practice)) {
                write( (ob==me ? "你" : ob->name(1)) + "目前并没有学会任何技能。\n");
                return 1;
        }

        if( !mapp(skill_learn) ) skill_learn = ([]);
        if( !mapp(skill_practice) ) skill_practice = ([]);

        write(HIG+ (ob==me ? "你" : ob->name(1)) +"目前所学过的技能：\n"+NOR);
        write(HIG "────────────────────────────────────────────────\n" NOR);
        printf(HIG "%-40s%-18s%-18s\n","            技能名称","       学习水平","               应用水平");
        write(HIG "────────────────────────────────────────────────\n" NOR);

        sname  = sort_array( keys(skill_learn), (: strcmp :) );
        sname_p  = sort_array( keys(skill_practice), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        skill_learned = ob->query_learned();
        skill_practiced = ob->query_practiced();

        if( !mapp(skill_learned) ) skill_learned = ([]);
        if( !mapp(skill_practiced) ) skill_practiced = ([]);
                
        for(i=0; i<sizeof(keys(skill_learn)); i++) {
        
                printf("%s%s%-38s" NOR "%-10s %3d/%5d        %-10s %3d/%5d\n", 
                        (skill_learned[sname[i]] >= (skill_learn[sname[i]]+1) * (skill_learn[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "□"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",
                        skill_level("learn", skill_learn[sname[i]]),
                        skill_learn[sname[i]], (int)skill_learned[sname[i]],
                        skill_level("practice", skill_practice[sname[i]]),
                        skill_practice[sname[i]], (int)skill_practiced[sname[i]],

                );
        }
        for(i=0; i<sizeof(keys(skill_practice)); i++) {
                if(!sizeof(keys(skill_learn)))
                        printf("%s%s%-38s" NOR "%-10s %3d/%5d        %-10s %3d/%5d\n", 
                                (skill_learned[sname_p[i]] >= (skill_learn[sname_p[i]]+1) * (skill_learn[sname_p[i]]+1)) ? HIM : "",
                                (member_array(sname_p[i], mapped)==-1? "  ": "□"),
                                to_chinese(sname_p[i]) + " (" + sname_p[i] + ")",
                                skill_level("learn", skill_learn[sname_p[i]]),
                                skill_learn[sname_p[i]], (int)skill_learned[sname_p[i]],
                                skill_level("practice", skill_practice[sname_p[i]]),
                                skill_practice[sname_p[i]], (int)skill_practiced[sname_p[i]],

                        );
                else if(member_array(sname_p[i],keys(skill_learn))==-1)
                        printf("%s%s%-38s" NOR "%-10s %3d/%5d        %-10s %3d/%5d\n", 
                                (skill_learned[sname_p[i]] >= (skill_learn[sname_p[i]]+1) * (skill_learn[sname_p[i]]+1)) ? HIM : "",
                                (member_array(sname_p[i], mapped)==-1? "  ": "□"),
                                to_chinese(sname_p[i]) + " (" + sname_p[i] + ")",
                                skill_level("learn", skill_learn[sname_p[i]]),
                                skill_learn[sname_p[i]], (int)skill_learned[sname_p[i]],
                                skill_level("practice", skill_practice[sname_p[i]]),
                                skill_practice[sname_p[i]], (int)skill_practiced[sname_p[i]],

                        );


        }
        write(HIG "────────────────────────────────────────────────\n" NOR);
        return 1;
}

string skill_level(string type, int level)
{
        int grade;

        grade = level / 20;

        switch(type) {
                case "learn":
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
        write(@HELP
指令格式 : skills|cha [<某人>]

这个指令可以让你(你)查询所学过的技能。

你也可以指定一个和你有师徒关系的对象，用 skills 可以查知对方的技能状况。

巫师可以查询任何人或 NPC 的技能状况。

HELP
    );
    return 1;
}
