#___SETUP
NAME_TRAIN				= 	LinearRegressionTrain
NAME_ESTIMATE			= 	LinearRegressionEstimate

CC								=	c++
CFLAGS						=	#-Wall -Wextra -Werror
RM								=	rm -rf

#	FILE & PATH
HEADER						= lib/LinearRegression.hpp

SRCS_TRAIN				= 	src/mainTrain.cpp \
											lib/LinearRegression.cpp \
											src/normalize.cpp

SRCS_ESTIMATE			= 	src/mainEstimate.cpp \
											lib/LinearRegression.cpp \
											src/normalize.cpp

DIR_OBJS_TRAIN		=	.objs/train
DIR_OBJS_ESTIMATE	=	.objs/estimate

LST_OBJS_TRAIN		=	$(SRCS_TRAIN:.cpp=.o)
LST_OBJS_ESTIMATE	=	$(SRCS_ESTIMATE:.cpp=.o)

OBJS_TRAIN				=	$(addprefix $(DIR_OBJS_TRAIN)/,$(LST_OBJS_TRAIN))
OBJS_ESTIMATE			=	$(addprefix $(DIR_OBJS_ESTIMATE)/,$(LST_OBJS_ESTIMATE))


all:								${NAME_TRAIN} ${NAME_ESTIMATE} params

${NAME_TRAIN}:			${OBJS_TRAIN}
			$(CC) $(CFLAGS) $^ -o $@

${NAME_ESTIMATE}:		${OBJS_ESTIMATE}
			$(CC) $(CFLAGS) $^ -o $@

$(DIR_OBJS_TRAIN)/%.o:	%.cpp $(HEADER) Makefile $(HEADER) | $(DIR_OBJS_TRAIN)
			$(CC) $(CFLAGS) -I. -c $< -o $@

$(DIR_OBJS_ESTIMATE)/%.o:	%.cpp $(HEADER) Makefile $(HEADER) | $(DIR_OBJS_ESTIMATE)
			$(CC) $(CFLAGS) -I. -c $< -o $@

$(DIR_OBJS_TRAIN):
			mkdir -p $(DIR_OBJS_TRAIN)/src $(DIR_OBJS_TRAIN)/lib

$(DIR_OBJS_ESTIMATE):
			mkdir -p $(DIR_OBJS_ESTIMATE)/src $(DIR_OBJS_ESTIMATE)/lib

params: 
	$(RM) ./csv/params.csv
	echo 'learningRate,theta0,teta1\n0.5,0,0' > ./csv/params.csv

clean:
			$(RM) .objs

fclean:				clean
			$(RM) ${NAME_TRAIN} ${NAME_ESTIMATE}

re:					fclean all

.PHONY:		all clean fclean re bonus params
