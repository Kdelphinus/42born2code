FROM nginx

COPY nginx.conf /etc/nginx/conf.d/default.conf
COPY index.html /nginx/index.html

CMD ["nginx", "-g", "daemon off;"]

EXPOSE 80