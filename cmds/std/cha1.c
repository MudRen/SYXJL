// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "��ѧէ��" NOR,
        HIB "��ͨƤë" NOR,
        HIB "��������" NOR,
        HIB "������" NOR,
        HIB "�������" NOR,
        CYN "�������" NOR,
        CYN "����似" NOR,
        CYN "�����뻯" NOR,
        HIC "�Ƿ��켫" NOR,
        HIC "һ����ʦ" NOR,
        HIW "��ɲ�" NOR
});

string *knowledge_level_desc = ({
        BLU "��ѧէ��" NOR,
        HIB "�����ž�" NOR,
        HIB "��֪һ��" NOR,
        HIB "������" NOR,
        HIB "����С��" NOR,
        CYN "�������" NOR,
        CYN "��Ȼ���" NOR,
        CYN "��Ȼ��ͨ" NOR,
        HIC "������˫" NOR,
        HIC "������" NOR,
        HIW "��ɲ�" NOR
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
                if (!ob || !me->visible(ob)) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
        }

        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) )
                return notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");

        skill_learn = ob->query_learn_skills();
        skill_practice = ob->query_practice_skills();
        if(!sizeof(skill_learn)&&!sizeof(skill_practice)) {
                write( (ob==me ? "��" : ob->name(1)) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
                return 1;
        }

        if( !mapp(skill_learn) ) skill_learn = ([]);
        if( !mapp(skill_practice) ) skill_practice = ([]);

        write(HIG+ (ob==me ? "��" : ob->name(1)) +"Ŀǰ��ѧ���ļ��ܣ�\n"+NOR);
        write(HIG "������������������������������������������������������������������������������������������������\n" NOR);
        printf(HIG "%-40s%-18s%-18s\n","            ��������","       ѧϰˮƽ","               Ӧ��ˮƽ");
        write(HIG "������������������������������������������������������������������������������������������������\n" NOR);

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
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
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
                                (member_array(sname_p[i], mapped)==-1? "  ": "��"),
                                to_chinese(sname_p[i]) + " (" + sname_p[i] + ")",
                                skill_level("learn", skill_learn[sname_p[i]]),
                                skill_learn[sname_p[i]], (int)skill_learned[sname_p[i]],
                                skill_level("practice", skill_practice[sname_p[i]]),
                                skill_practice[sname_p[i]], (int)skill_practiced[sname_p[i]],

                        );
                else if(member_array(sname_p[i],keys(skill_learn))==-1)
                        printf("%s%s%-38s" NOR "%-10s %3d/%5d        %-10s %3d/%5d\n", 
                                (skill_learned[sname_p[i]] >= (skill_learn[sname_p[i]]+1) * (skill_learn[sname_p[i]]+1)) ? HIM : "",
                                (member_array(sname_p[i], mapped)==-1? "  ": "��"),
                                to_chinese(sname_p[i]) + " (" + sname_p[i] + ")",
                                skill_level("learn", skill_learn[sname_p[i]]),
                                skill_learn[sname_p[i]], (int)skill_learned[sname_p[i]],
                                skill_level("practice", skill_practice[sname_p[i]]),
                                skill_practice[sname_p[i]], (int)skill_practiced[sname_p[i]],

                        );


        }
        write(HIG "������������������������������������������������������������������������������������������������\n" NOR);
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
ָ���ʽ : skills|cha [<ĳ��>]

���ָ���������(��)��ѯ��ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills ���Բ�֪�Է��ļ���״����

��ʦ���Բ�ѯ�κ��˻� NPC �ļ���״����

HELP
    );
    return 1;
}
