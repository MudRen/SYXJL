// banname.c

// writed by shadow



void create()

{

	seteuid(getuid());

}



int main(object me, string arg)

{

//         string banname, banname1, *banname2;
          string banname;
	int i;



	if (!arg)

	{

		if ( file_size(CONFIG_DIR + "banned_name") >=0 )

			me->start_more(read_file(CONFIG_DIR + "banned_name"));

		else

			write("û�н�ֹ���������֡�\n");

		return 1;

	}

	else if (sscanf(arg, "+ %s", banname) == 1)

	{

		i = strlen(banname);



		while(i--)

		{

			if ( (strlen(banname) < 2) || (strlen(banname) > 12 ) )

			{

				write("���ܽ�ֹ " + banname + "���������ֱ����� 1 �� 6 �������֡�\n");

				return 1;

			}

			if ( banname[i]<=' ' )

			{

				write("���ܽ�ֹ " + banname + "���������ֲ����ÿ�����Ԫ��\n");

				return 1;

			}

			if ( i%2==0 && !is_chinese(banname[i..<0]) )

			{

				write("���ܽ�ֹ " + banname + "�����á����ġ�ȡ���֡�\n");

				return 1;

			}

		}

		write_file(CONFIG_DIR + "banned_name", banname + "\n" );

		write("OK.\n");

	}

	else if (sscanf(arg, "- %s", banname) == 1)

	{

		write("���޸� " + CONFIG_DIR + "banned_name" + " �����\n");

	}

	else write("ָ���ʽ��banname [+|- chinesename]\n");



	return 1;

}



int help(object me)

{

	write(@HELP

ָ���ʽ��banname [+|- chinesename]



����������������ֹ�������������������֡�

HELP

	);

	return 1;

}

