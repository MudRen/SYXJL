
//modified by tlang for /cmds/std/look.c
//this is for descripe a person's bellicosit for look.c
nosave string *all_exits = ({
    "east",
    "south",
    "west",
    "north",
    "eastup",
    "southup",
    "westup",
    "northup",
    "eastdown",
    "southdown",
    "westdown",
    "northdown",
    "northeast",
    "northwest",
    "southeast",
    "southwest",
    "up",
    "down",
    "enter",
    "out",
});

string *bel_msg_male1 = ({
        "����¶��������ɱ����",
        "����ͷ����������˲����׽���",
});

string *bel_msg_male2 = ({
        "üͷ�������ƺ���Щ���¡�",
        "���ϸ��ֳ�һ��Ű����",
});

string *bel_msg_male3 = ({
        "����¶�����õ�Ц�ݡ�",
        "����¶������΢Ц��",
});

string *bel_msg_female1 = ({
        "����������˲����׽���",
        "������͸��һЩɱ����",
});

string *bel_msg_female2 = ({
        "üͷ�������ƺ���Щ���¡�",
        "��Щ������ˡ�",
});

string *bel_msg_female3 = ({
        "�����Ц�š�",
        "����Ц�š�",
        "����ȥ������а��",
});

string *bel_msg_nomale1 = ({
        "�ƺ���ʲô���¡�",
        "�۹⵽����������֪��������Ѱʲô��",
});

string *bel_msg_nomale2 = ({
        "����̾Ϣ���۹�������Ī�������ˡ�",
        "Ŀ�����أ�Ҳ��֪������ʲôа�ˡ�",
});

string *bel_msg_nomale3 = ({
        "¶��һ��Ī�������������顣",
        "�˷�Ī����Ҳ��֪��Ϊʲô��",
        "¶��һ�ֲ������ı��顣",
});

string bel_status_msg(int shen,string gender)
{
        if ( gender == "����" ) {
                if ( shen < -500 )
                return ( bel_msg_male1[random(sizeof(bel_msg_male1))]);
                else if ( shen < 0 )
                return ( bel_msg_male2[random(sizeof(bel_msg_male2))]);
                else if ( shen>=0 )
                return ( bel_msg_male3[random(sizeof(bel_msg_male3))]);
        }
        if ( gender == "Ů��" ) {
                if ( shen>=-500 )
                return ( bel_msg_female1[random(sizeof(bel_msg_female1))]);
                else if ( shen< 0)
                     return ( bel_msg_female2[random(sizeof(bel_msg_female2))]);
                else if ( shen>=0 )
                return ( bel_msg_female3[random(sizeof(bel_msg_female3))]);
        }
       else {
                if ( shen>=-500 )
                return ( bel_msg_nomale1[random(sizeof(bel_msg_nomale1))]);
                else if ( shen< 0 )
                        return ( bel_msg_nomale2[random(sizeof(bel_msg_nomale2))]);
                else if ( shen>=0 )
                return ( bel_msg_nomale3[random(sizeof(bel_msg_nomale3))]);
        }
}

//this is for descripe a person's per.
string *per_msg_male1 = ({
        "Ӣ������,������棬�����˰�����������" ,
        "��ò����,��Ŀ���ʣ���Ŀ���飬��ü¶����" ,
});

string *per_msg_male2 = ({
        "Ӣ������,������档",
        "��ò����,��Ŀ���ʡ�",
});
string *per_msg_male3 = ({
        "��òƽƽ��ûʲ��ÿ��ġ�",
        "��������ģ�һ���޾���ɵ�ģ����",
        "��ò�׶��������⡣",
});
string *per_msg_female1 = ({
        "��ɫ���������˴�Լ����һ��˵�����ķ�����̬��",
        "�������ƣ�����ʤѩ����֪�㵹�˶���Ӣ�ۺ��ܡ� ",
        "������������Ŀ���飬����һЦ������������Ȼ�Ķ���",
        "�������֣��������ˣ��������Ҽ
�������",
});

string *per_msg_female2 = ({
        "��ɫ���������˴�Լ����һ��˵�����ķ�����̬��" ,
        "�������ƣ�����ʤѩ����֪�㵹�˶���Ӣ�ۺ��ܡ� ",
        "������������Ŀ���飬����һЦ������������Ȼ�Ķ���",
        "�������֣��������ˣ��������Ҽ������� ",
});

string *per_msg_female3 = ({
        "���㲻�Ͼ������ˣ�Ҳ���м�����ɫ�� ",
        "���û��������м�����ɫ��  ",
});

string *per_msg_nomale1 = ({
        "�������磬�������ˣ�Ҳ������������Ů��" ,
        "ü��Ŀ�㣬������������ȴ���߷�����ࡣ ",
});
string *per_msg_nomale2 = ({
        "��Ŀ���㣬ֻ������¶��һ��Ů����֬������",
        "����ȥҲ��֪����������������ǵ�Цȴ�����˺�Ů�˶���Щ�Ķ��� ",
});

string *per_msg_nomale3 = ({
        "���û����ԣ�ֻ�Ǽ�û�����˵Ĵ����ȱ��Ů�ӵ����ᡣ ",
        "�������е��������������ȴ��ЩŤ����̬�����в�Ů��",
});


string per_status_msg(int per, string gender)
{
        if ( gender == "����" ) {
                if ( per>=25 )
                return ( per_msg_male1[random(sizeof(per_msg_male1))]);
                else if ( per>=20 )
                return ( per_msg_male2[random(sizeof(per_msg_male2))]);
                else if ( per<20 )
                return ( per_msg_male3[random(sizeof(per_msg_male3))]);
    }
        if ( gender == "Ů��" ) {
                if ( per>=25 )
                return ( per_msg_female1[random(sizeof(per_msg_female1))]);
                else if ( per>=20 )
                        return ( per_msg_female2[random(sizeof(per_msg_female2))]);
                else if ( per<20 )
                return ( per_msg_female3[random(sizeof(per_msg_female3))]);

    }
        else {
                if ( per>=25 )
                return ( per_msg_nomale1[random(sizeof(per_msg_nomale1))]);
                else if ( per>=20 )
                return ( per_msg_nomale2[random(sizeof(per_msg_nomale2))]);
                else if ( per<20 )
                return ( per_msg_nomale3[random(sizeof(per_msg_nomale3))]);
    }
}
string *look_level_boy = ({
 BLU "ü����б����ͷѢ�ţ���������" NOR,
 BLU "�������죬������ף�����ޱ�" NOR,
 BLU "�����Ƥ��ͷ���������˲����ٿ��ڶ���" NOR,
 HIB "��ü���ۣ�������ߣ�������״" NOR,
 HIB "��ͷ�������Բ��ģ��ֽŶ̴֣����˷�Ц" NOR,
 NOR "��հ��ݣ��ݹ����꣬������̾" NOR,
 NOR "ɵͷɵ�ԣ��ճպ�����������Ҳ��ʵ" NOR,
 NOR "��òƽƽ�������������ʲôӡ��" NOR,
 YEL "�����Բ���������⣬���ζ���" NOR,
 YEL "��Բ���������ڷ����Ǹ񲻷�" NOR,
 RED "üĿ���㣬�����󷽣�һ���˲�" NOR,
 RED "˫�۹⻪Ө��͸���������ǵĹ�â" NOR,
 HIY "�ٶ���������ˮ�����̷��飬������������Ŀ��" NOR,
 HIY "˫Ŀ���ǣ�ü�Ҵ��飬�������޲�Ϊ֮�Ķ�" NOR,
 HIR "�����촽�����˿��Σ���ֹ��������" NOR,
 HIR "��������Ŀ�����ǣ����˹�Ŀ����" NOR,
 MAG "�������񣬷�ױ��������������" NOR,
 MAG "Ʈ�ݳ�������������" NOR,
 MAG "�����ʣ��������������������ٷ�" NOR,
 HIM "������ˬ���Ǹ����棬��������" NOR,
 HIM "һ���������ȣ��ɷ���ǣ���ֹ����" NOR,
});

string *look_level_girl = ({
  BLU "�������Σ�״��ҹ��" NOR,
  BLU "���б�ۣ���ɫ�Ұܣ�ֱ����һ��" NOR,
  BLU "����ü�������ۣ���Ƥ�Ʒ�������һ��������" NOR,
  HIB "��С�綹��üëϡ�裬�����צ����������" NOR,
  HIB "һ�����������һ����û�ø�" NOR,
  NOR "�������Ƥɫ�ֺڣ���ª����" NOR,
  NOR "�ɻƿ��ݣ���ɫ���ƣ�����Ů��ζ" NOR,
  YEL "�����С�������޹⣬��������" NOR,
  YEL "�䲻���£���Ҳ�׾�����Щ����֮��" NOR,
  RED "����΢�ᣬ�ŵ��������¿���" NOR,
  RED "�������ģ�����Ө͸��������˼" NOR,
  HIR "��С���磬���������������������" NOR,
  HIR "�������󣬼���ʤѩ��Ŀ����ˮ" NOR,
  HIW "���۰���������ҩ���̣����￴��" NOR,
  HIW "����ϸ������欶��ˣ�����һ������������" NOR,
  MAG "�����������������£�����ܳ�������" NOR,
  MAG "üĿ�续������ʤѩ�����ν�����߻�" NOR,
  MAG "�������������Ż���ɽ�����˼�֮����" NOR,
  HIM "������ϼ���������񣬻�����������" NOR,
  HIM "�������ɣ���մһ˿�̳�" NOR,
  HIM "����"+HIW+"������"+HIM+"�������ƻã��Ѳ����Ƿ�������" NOR,
});
  
 string *tough_level_desc = ({
        BLU "����һ��" NOR,
        BLU "��������" NOR,
        BLU "����ҳ�" NOR,
        BLU "��ѧէ��" NOR,
        HIB "�����ž�" NOR,
        HIB "��֪һ��" NOR,
        HIB "����ͨͨ" NOR,
        HIB "ƽƽ����" NOR,
        HIB "ƽ������" NOR,
        HIB "��ͨƤë" NOR,
        HIB "��������" NOR,
        HIB "������" NOR,
        HIB "����С��" NOR,
        HIB "����С��" NOR,
        HIB "�������" NOR,
        CYN "�������" NOR,
        CYN "��Ȼ���" NOR,
        CYN "���д��" NOR,
        CYN "���д��" NOR,
        CYN "��Ȼ��ͨ" NOR,
        CYN "�������" NOR,
        CYN "�޿�ƥ��" NOR,
        CYN "����Ⱥ��" NOR,
        CYN "����似" NOR,
        CYN "�����뻯" NOR,
        CYN "����Ⱥ��" NOR,
        HIC "�Ƿ��켫" NOR,
        HIC "��������" NOR,
        HIC "һ����ʦ" NOR,
        HIC "�񹦸���" NOR,
        HIC "������˫" NOR,
        HIC "��������" NOR,
        HIC "������" NOR,
        HIC "��ز�¶" NOR,
        HIR "��ɲ�" NOR
});
string *heavy_level_desc= ({
        "����",
        "����",
        "����",
        "����",
        "����",
        "����"
}); 
