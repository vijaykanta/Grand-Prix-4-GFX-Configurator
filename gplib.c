/**
* @author Vijay Kanta
* @website www.vizcreations.com
* @abstract Simple console configurator for game Grand Prix 4
* @license Free software - No guarantee
* @copyright Not applicable
* @link https://github.com/vijaykanta/gp4_gfx_config.git
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gplib.h"

void strip_newline(char *str, int len) {
	int i = 0;
	for(i=0; i<len; i++) {
		if(str[i] == '\n') {
			str[i] = '\0';
			break;
		}
	}
}

void strip_tab(char *str, int len) {
	int i = 0;
	for(i=0; i<len; i++) {
		if(str[i] == '\t') {
			str[i] = '\0';
			break;
		}
	}
}

void save_file(CFG *cfg) {
	printf("Generating new configuration file from buffer..\n");
	cfg->fp = fopen("f1graphics.cfg", "w");
	if(!cfg->fp) {
		printf("Couldn't write file!\n");
	} else {
		for(i=0; i<cfg->tot_lines; i++) {
			fprintf(cfg->fp, "%s\n", cfg->all_lines[i]);
		}
		fclose(cfg->fp);
		printf("New configuration file created successfully!\n");
	}
}

void show_file_contents(CFG *cfg) {
	char *buff;
	int counter = 0;
	cfg->fp = fopen(cfg->file_name, "r");
	//if(sizeof(buff) > 0) free(buff);
	buff = (char *) malloc(sizeof(char) * MAX_LINE);
	while(fgets(buff, MAX_LINE, cfg->fp)) {
		printf("%d: %s", counter, buff);
		free(buff);
		buff = (char *) malloc(sizeof(char) * MAX_LINE);
		++counter;
	}
	free(buff);
}

void get_val_cmt_(CFG *cfg) {
	if(sizeof(buff) > 0) free(buff);
	if(sizeof(value) > 0) free(value);
	if(sizeof(comment) > 0) free(comment);

	buff = (char *) malloc(sizeof(char) * MAX_LINE);
	value = (char *) malloc(sizeof(char) * MAX_VAL);
	comment = (char *) malloc(sizeof(char) * MAX_LINE);
	
	strcpy(buff, cfg->all_lines[cfg->cur_sel]);
	token = strtok(buff, ";");

	if(token != NULL) {
		//value[0] = '\0';
		strcpy(value, token);
		strip_tab(value, MAX_VAL);
	}

	token = strtok(NULL, ";");

	if(token != NULL) {
		//comment[0] = '\0';
		strcpy(comment, token);
		strip_newline(comment, MAX_LINE);
	}

}

void set_val_cmt_(CFG *cfg) {
	int last;
	free(cfg->all_lines[cfg->cur_sel]);
	cfg->all_lines[cfg->cur_sel] = (char *) malloc(sizeof(char) * MAX_LINE);
	cfg->all_lines[cfg->cur_sel][0] = '\0';

	free(value);
	value = (char *) malloc(sizeof(char) * MAX_VAL);
	//value[0] = '\0';

	sprintf(value, "%d\t\t\t", val);
	strcat(cfg->all_lines[cfg->cur_sel], value);
	strcat(cfg->all_lines[cfg->cur_sel], ";");
	strcat(cfg->all_lines[cfg->cur_sel], comment);

	last = strlen(cfg->all_lines[cfg->cur_sel]) + 1;
	cfg->all_lines[cfg->cur_sel][last] = '\0';
}

void show_cur_val(CFG *cfg) {
	printf("Change settings as below:\n");
	printf("%s\n", comment);
}

void init_vals(CFG *cfg) {
	cfg->tex_fil_qlty_key = 98;
	cfg->tex_fil_qlty_cmt = (char *) malloc(sizeof(char) * MAX_LEN);
	cfg->tex_fil_qlty = 0;
	
	cfg->track_map_key = 54;
	cfg->track_map_cmt = (char *) malloc(sizeof(char) * MAX_LEN);
	cfg->track_map = 0;

	cfg->env_map_key = 64;
	cfg->env_map_cmt = (char *) malloc(sizeof(char) * MAX_LEN);
	cfg->env_map = 0;

	cfg->tex_qlty_key = 23;
	cfg->tex_qlty_cmt = (char *) malloc(sizeof(char) * MAX_LEN);
	cfg->tex_qlty = 0;

	cfg->an_fil_qlty_key = 100;
	cfg->an_fil_qlty_cmt = (char *) malloc(sizeof(char) * MAX_LEN);
	cfg->an_fil_qlty = 0;

	cfg->shdw_type_key = 108;
	cfg->shdw_type_cmt = (char *) malloc(sizeof(char) * MAX_LEN);
	cfg->shdw_type = 0;
}

void free_vals(CFG *cfg) {
	free(cfg->tex_fil_qlty_cmt);
	free(cfg->track_map_cmt);
	free(cfg->env_map_cmt);
	free(cfg->tex_qlty_cmt);
	free(cfg->an_fil_qlty_cmt);
	free(cfg->shdw_type_cmt);
}

void read_file(CFG *cfg) {
	int num;
	FILE *handler;
	printf("Now reading contents of file..\n");

	cfg->tot_lines = 0;
	free(cfg->all_lines);
	free(cfg->cur_line);
	cfg->all_lines = (char **) malloc(sizeof(char) * MAX_LINE * MAX_LINES);
	cfg->cur_line = (char *) malloc(sizeof(char) * MAX_LINE);

	while(fgets(cfg->cur_line, MAX_LINE, cfg->fp)) {
		strip_newline(cfg->cur_line, MAX_LINE);
		if(strlen(cfg->cur_line) > 0) {
			cfg->all_lines[cfg->tot_lines] = (char *) malloc(sizeof(char) * MAX_LINE);
			strcpy(cfg->all_lines[cfg->tot_lines], cfg->cur_line);
			free(cfg->cur_line);
			cfg->cur_line = (char *) malloc(sizeof(char *) * MAX_LINE);
			++cfg->tot_lines;
		}
	}
	fclose(cfg->fp);

	printf("Now creating backup file..\n");
	handler = fopen("f1graphics.cfg.backup", "w");
	if(handler) {
		for(num=0; num<cfg->tot_lines; num++) {
			fprintf(handler, "%s\n", cfg->all_lines[num]);
		}
		fclose(handler);
		printf("Created backup file successfully..\n");
	}

	init_vals(cfg);
}