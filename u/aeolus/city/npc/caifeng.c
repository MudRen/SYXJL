// waiter.c

inherit NPC;

int check_legal_name(string arg);

int check_legal_id(string arg);



void create()

{

	set_name("�ϲ÷�", ({ "caifeng" }) );

	set("gender", "����" );

	set("age", 52);

	set("long",

		"��λ�ϲ÷���Ц�����æ��������ʱ�Ĳ�һ���Լ����ϻ��ۡ�\n");

	set("combat_exp", 5);

	set("attitude", "friendly");

	setup();



}



void init()

{	

	object ob;



	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) {

		remove_call_out("greeting");

		call_out("greeting", 1, ob);

	}

	add_action("do_ding", "ding");



}



void greeting(object ob)

{

	if( !ob || environment(ob) != environment() ) return;

	switch( random(5) ) {

		case 0:

			say( "�ϲ÷�Ц�����˵������λ" + RANK_D->query_respect(ob)

				+ "�����������·��ɡ�\n");

			break;

		case 1:

			say( "�ϲ÷��ü����˵������λ" + RANK_D->query_respect(ob)

				+ "���������ְ�����ﲻ���㡣\n");

			break;

	}

}



int do_ding(string arg)

{

	string ctype, cname, ccolor, cid, material;

	object ob, me, gold, ob2;

	string id,newfile,filename,timestamp;

        me = this_player();

	id = me->query("id");

        if(!arg || sscanf(arg,"%s %s %s %s %s",ctype,ccolor,cname,cid,material ) != 5)

        return notify_fail("ָ���ʽ��ding <type> <color> <name> <English name> <material>\n");

	if(me->is_busy())

	return notify_fail("����һ��������û����ɡ�\n");

        if((int)me->query("created_item") >= (int)me->query("age")/11)

        return notify_fail("������ֻ��ӵ��"+chinese_number((int)me->query("age")/11)+

"��������Ʒ��\n");

	if((int)me->query("created_item") >= 3)

	return notify_fail("���Ѿ�ӵ��̫��������Ʒ�ˡ�\n");

	gold = present("gold_money", this_player());

        if(!gold) return notify_fail("������û�н��ӡ�\n");

        if((int) gold->query_amount() < 1)

        return notify_fail("������û���������ӡ�\n");

        if(!objectp(ob2=present(material,me)))

        return notify_fail("�����ϲ�û��"+material+"��\n");

        if(!(int)ob2->query("for_create_cloth"))

        return notify_fail(ob2->name()+"�����������������Ρ�\n");

	if( !check_legal_name(cname))

	return notify_fail("");

        if( !check_legal_id(cid))

        return notify_fail("");



	if( ccolor != "$BLK$" && 

	    ccolor != "$NOR$" &&

            ccolor != "$RED$" &&

            ccolor != "$GRN$" &&

            ccolor != "$YEL$" &&

            ccolor != "$BLU$" &&

            ccolor != "$MAG$" &&

            ccolor != "$CYN$" &&

            ccolor != "$WHT$" &&

            ccolor != "$NOR$" &&

            ccolor != "$HIR$" &&

            ccolor != "$HIG$" &&

            ccolor != "$HIY$" &&

            ccolor != "$HIB$" &&

            ccolor != "$HIM$" &&

            ccolor != "$HIC$" &&

            ccolor != "$HIW$" 

	)

	return notify_fail("��֪��Ҫʲô��ɫ��\n");

        ccolor = replace_string(ccolor, "$BLK$", "BLK");

        ccolor = replace_string(ccolor, "$RED$", "RED");

        ccolor = replace_string(ccolor, "$GRN$", "GRN");

        ccolor = replace_string(ccolor, "$YEL$", "YEL");

        ccolor = replace_string(ccolor, "$BLU$", "BLU");

        ccolor = replace_string(ccolor, "$MAG$", "MAG");

        ccolor = replace_string(ccolor, "$CYN$", "CYN");

        ccolor = replace_string(ccolor, "$WHT$", "WHT");

        ccolor = replace_string(ccolor, "$HIR$", "HIR");

        ccolor = replace_string(ccolor, "$HIG$", "HIG");

        ccolor = replace_string(ccolor, "$HIY$", "HIY");

        ccolor = replace_string(ccolor, "$HIB$", "HIB");

        ccolor = replace_string(ccolor, "$HIM$", "HIM");

        ccolor = replace_string(ccolor, "$HIC$", "HIC");

        ccolor = replace_string(ccolor, "$HIW$", "HIW");

        ccolor = replace_string(ccolor, "$NOR$", "NOR");

	seteuid(ROOT_UID);

	switch( ctype ) {

		case "hat":

			newfile = read_file("/obj/clothes/hat.o");

			break;

                case "belt":

                        newfile = read_file("/obj/clothes/belt.o");

                        break;

                case "shoes":

                        newfile = read_file("/obj/clothes/shoes.o");

                        break;

                case "suit":

                        newfile = read_file("/obj/clothes/suit.o");

                        break;

                case "scarf":

                        newfile = read_file("/obj/clothes/scarf.o");

                        break;

		default:

			return notify_fail("���ﲻ������Ҫ�Ķ�����\n");

	}

        timestamp = sprintf("%c%c%c%c%c%c%c",'a'+random(20),'a'+random(20),'a'+random(20),

	'a'+random(20),'a'+random(20),'a'+random(20),'a'+random(20));

	newfile = replace_string( newfile, "������", cname);

        newfile = replace_string( newfile, "order", cid);

        newfile = replace_string( newfile, "fengyun", id);

        newfile = replace_string( newfile, "COR", ccolor);

        newfile = replace_string( newfile, "STAMP", timestamp);

	if(file_size(DATA_DIR+"login/" + id[0..0] + "/" + id)!=-2)

		mkdir(DATA_DIR+"login/" + id[0..0] + "/" + id);

        filename = DATA_DIR+"login/" + id[0..0] + "/" + id + "/" + id +timestamp + ".c";

	if( !write_file(filename, newfile,1))

		return 0;

	ob = new(filename);

        if(ob2->query("equipped")) {ob2->unequip(); me->reset_action();}

        ob2->move(environment(me));

        ob->set("weight",ob2->query_weight());

        ob->set("armor_prop/armor",ob2->query("armor_prop/armor"));

        ob->set("max_enchant",ob2->query("max_enchant"));

        ob->set("base_armor",ob2->query("armor_prop/armor"));

        ob->save();

        ob->restore();

        if(ob->move(me)){

        gold->add_amount(-1);

        me->add("created_item",1);

        me->start_busy(1);

        write("�㽫���ϵ�"+ob2->name()+"����"+name()+"�������һ"+ob->query("unit")+

        ob->name()+"\n");

        destruct(ob2);

        seteuid(getuid());

	return 1;

	}

	return 0;

}

int check_legal_name(string name)

{

        int i;

        i = strlen(name);

        if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {

                write("�Բ����������ֱ�����һ����ʮ�������֡�\n");

                return 0;

        }

        while(i--) {

                if( name[i]<=' ' ) {

                        write("�Բ����������ֲ����ÿ�����Ԫ��\n");

                        return 0;

                }

                if( i%2==0 && !is_chinese(name[i..<0]) ) {

                        write("�Բ������ֱ��������ġ�\n");

                        return 0;

                }

        }

        return 1;

}



int check_legal_id(string name)

{

        int i;

        i = strlen(name);

        if( (strlen(name) < 3) || (strlen(name) > 20 ) ) {

                write("�Բ���Ӣ�����ֱ�����������ʮ�����֡�\n");

                return 0;

        }



	return 1;

}
